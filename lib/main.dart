import 'dart:convert';
import 'dart:io';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:loading_animation_widget/loading_animation_widget.dart';
import 'dart:async';
import 'package:path_provider/path_provider.dart';
import 'package:record_mp3/record_mp3.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:bemba_lingo/bemba_api.dart';
import 'package:google_fonts/google_fonts.dart';
import 'colors.dart';

void main() {
  SystemChrome.setSystemUIOverlayStyle(const SystemUiOverlayStyle(
    statusBarColor: Colors.transparent,
    systemNavigationBarColor: bgColor,
  ));
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String statusText = "";
  bool isComplete = false;
  String transcriptionResponse = "";
  bool showTranscription = true;
  bool isLoading = false;

  Future<bool> checkPermission() async {
    if (!await Permission.microphone.isGranted) {
      PermissionStatus status = await Permission.microphone.request();
      if (status != PermissionStatus.granted) {
        return false;
      }
    }
    return true;
  }

  void startRecord() async {
    setState(() {
      showTranscription = false;
    });
    bool hasPermission = await checkPermission();
    if (hasPermission) {
      statusText = "Recording...";
      recordFilePath = await getFilePath();
      isComplete = false;
      RecordMp3.instance.start(recordFilePath, (type) {
        statusText = "Record error--->$type";
        setState(() {});
      });
    } else {
      statusText = "No microphone permission";
    }
    setState(() {});
  }

  void pauseRecord() {
    if (RecordMp3.instance.status == RecordStatus.PAUSE) {
      bool s = RecordMp3.instance.resume();
      if (s) {
        statusText = "Recording...";
        setState(() {});
      }
    } else {
      bool s = RecordMp3.instance.pause();
      if (s) {
        statusText = "Recording paused...";
        setState(() {});
      }
    }
  }

  void stopRecord() {
    bool s = RecordMp3.instance.stop();
    if (s) {
      statusText = "Recording done...";
      isComplete = true;
      setState(() {});
    }
  }

  void resumeRecord() {
    bool s = RecordMp3.instance.resume();
    if (s) {
      statusText = "Recording...";
      setState(() {});
    }
  }

  late String recordFilePath;

  Future<void> transcribeBemba() async {
    statusText = '';
    setState(() {
      isLoading = true; // Set loading to true when starting transcription
    });
    if (recordFilePath != null && File(recordFilePath).existsSync()) {
      try {
        final response = await bembaTranscription(recordFilePath);
        Map<String, dynamic> jsonResponse = jsonDecode(response);

        setState(() {
          if (jsonResponse.isNotEmpty) {
            var jsonResponseValues = jsonResponse.values;
            String jsonResponseValuesMinusParentheses = jsonResponseValues.toString();
            transcriptionResponse = jsonResponseValuesMinusParentheses.substring(1, jsonResponseValuesMinusParentheses.length - 1);
            showTranscription = true;
          }
        });
      } finally {
        setState(() {
          isLoading = false; // Set loading to false when transcription is done
        });
      }
    } else {
      setState(() {
        isLoading = false; // Set loading to false if the file does not exist
      });
    }
  }

  int i = 0;

  Future<String> getFilePath() async {
    Directory storageDirectory = await getApplicationDocumentsDirectory();
    String sdPath = storageDirectory.path + "/record";
    var d = Directory(sdPath);
    if (!d.existsSync()) {
      d.createSync(recursive: true);
    }
    return sdPath + "/test_${i++}.mp3";
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(fontFamily: GoogleFonts.openSans().fontFamily),
      home: Scaffold(
        appBar: AppBar(
          leading: const Icon(Icons.sort_rounded, color: Colors.white),
          backgroundColor: bgColor,
          elevation: 0.0,
          title: const Text('Bemba Lingo'),
        ),
        body: Center(
          child: Column(
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  Padding(
                    padding: const EdgeInsets.fromLTRB(10.0, 20.0, 10.0, 10.0),
                    child: GestureDetector(
                      onTap: () async {
                        HapticFeedback.lightImpact();
                        startRecord();
                      },
                      child: Container(
                        height: 80,
                        width: 80,
                        decoration: BoxDecoration(
                          color: Colors.red.shade300,
                          borderRadius: BorderRadius.circular(50),
                        ),
                        child: const Center(
                          child: Icon(
                            Icons.circle,
                            color: Colors.white,
                            size: 40,
                          ),
                        ),
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.fromLTRB(10.0, 20.0, 10.0, 10.0),
                    child: GestureDetector(
                      onTap: () {
                        HapticFeedback.lightImpact();
                        pauseRecord();
                      },
                      child: Container(
                        height: 80,
                        width: 80,
                        decoration: BoxDecoration(
                          color: Colors.blue.shade300,
                          borderRadius: BorderRadius.circular(50.0),
                        ),
                        child: const Center(
                          child: Icon(
                            Icons.pause,
                            color: Colors.white,
                            size: 40,
                          ),
                        ),
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.fromLTRB(10.0, 20.0, 10.0, 10.0),
                    child: GestureDetector(
                      onTap: () {
                        HapticFeedback.lightImpact();
                        stopRecord();
                      },
                      child: Container(
                        height: 80,
                        width: 80,
                        decoration: BoxDecoration(
                          color: Colors.red,
                          borderRadius: BorderRadius.circular(50),
                        ),
                        child: const Center(
                          child:
                              Icon(Icons.stop, color: Colors.white, size: 40),
                        ),
                      ),
                    ),
                  ),
                ],
              ),
              Padding(
                padding: const EdgeInsets.only(top: 20.0),
                child: Text(
                  statusText,
                  style: const TextStyle(color: Colors.red, fontSize: 20),
                ),
              ),
              Padding(
                padding: const EdgeInsets.only(top: 20.0),
                child: GestureDetector(
                  onTap: () {
                    HapticFeedback.lightImpact();
                    transcribeBemba();
                  },
                  child: isLoading
                      ? LoadingAnimationWidget.discreteCircle(
                          size: 80,
                          color: bgColor,
                          secondRingColor: Colors.black,
                          thirdRingColor: Colors.red,
                        )
                      : Container(
                          margin: const EdgeInsets.only(top: 10),
                          alignment: AlignmentDirectional.center,
                          height: 80,
                          width: 80,
                          decoration: BoxDecoration(
                            color: isComplete && recordFilePath != null
                                ? bgColor
                                : null,
                            borderRadius: BorderRadius.circular(50.0),
                          ),
                          child: isComplete && recordFilePath != null
                              ? const Icon(Icons.transcribe,
                                  color: Colors.white, size: 40)
                              : Container(),
                        ),
                ),
              ),
              if (showTranscription && transcriptionResponse.length > 0)
                Padding(
                    padding: const EdgeInsets.fromLTRB(20, 20, 20, 20),
                    child: Container(
                      margin: const EdgeInsets.fromLTRB(0, 20, 0, 0),
                      padding: const EdgeInsets.fromLTRB(20, 20, 20, 20),
                      decoration: BoxDecoration(
                          color: transcriptionResponse.length > 0 ? bgColor : null, // This line is edited
                          borderRadius: BorderRadius.circular(10)),
                      child: Text(
                        transcriptionResponse,
                        style: const TextStyle(
                            fontSize: 20,
                            color: Colors.white,
                            fontWeight: FontWeight.bold),
                      ),
                    )),
            ],
          ),
        ),
      ),
    );
  }
}
