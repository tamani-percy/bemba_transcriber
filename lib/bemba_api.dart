import 'package:http/http.dart' as http;

Future<String> bembaTranscription(String filename) async {
  const apiUrl = "https://api-inference.huggingface.co/models/csikasote/wav2vec2-large-xls-r-300m-bemba-fds";
  final headers = {
    "Authorization": "Bearer ",
  };

  var request = http.MultipartRequest('POST', Uri.parse(apiUrl));
  request.headers.addAll(headers);
  request.files.add(await http.MultipartFile.fromPath('file', filename));

  var response = await request.send();
  var responseBody = await response.stream.bytesToString();

  return responseBody;
}
