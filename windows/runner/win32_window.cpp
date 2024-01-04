1
00:00:01,440 --> 00:00:04,380
The order confirmation will be pretty simple.

2
00:00:04,890 --> 00:00:11,670
We will be displaying a basic text here like we will have to add one image inside the images folder

3
00:00:12,030 --> 00:00:13,170
that open this.

4
00:00:14,850 --> 00:00:22,410
And then if you open the project resources with the AP project intact, the images folder, I have provided

5
00:00:22,620 --> 00:00:23,820
this for images.

6
00:00:24,180 --> 00:00:28,440
You will copy them and paste them inside the images folder.

7
00:00:29,440 --> 00:00:37,310
Then if we go to snippet inside Section 11, I have to a that is needed for the order confirmation to

8
00:00:37,310 --> 00:00:40,120
you why we will copy and paste that.

9
00:00:40,870 --> 00:00:42,910
We do not have anything fancy here.

10
00:00:43,180 --> 00:00:46,060
We have order placed successfully order.

11
00:00:46,060 --> 00:00:46,600
No.

12
00:00:46,870 --> 00:00:53,770
We need to modify this with the actual order number and the image here will be the image that you just

13
00:00:53,770 --> 00:00:54,250
added.

14
00:00:54,730 --> 00:00:56,830
So you see we have the long leaf image.

15
00:00:57,160 --> 00:00:58,900
That is what we are using here.

16
00:00:59,320 --> 00:01:00,970
And we have some dummy text.

17
00:01:01,930 --> 00:01:04,239
There are two things that we have to work on.

18
00:01:04,430 --> 00:01:10,090
Insert the order confirmation page model was required the unit of work.

19
00:01:10,390 --> 00:01:11,890
So let me go to summary.

20
00:01:12,190 --> 00:01:13,840
Six months?

21
00:01:13,840 --> 00:01:14,350
Yes.

22
00:01:14,920 --> 00:01:18,880
And I will copy the unit of work it here.

23
00:01:19,420 --> 00:01:23,100
We do not need the enumerable order, the order header.

24
00:01:23,410 --> 00:01:25,780
We only need the a unit of work.

25
00:01:27,050 --> 00:01:31,430
Weather, make sure the constructor name is valid and perfect.

26
00:01:32,370 --> 00:01:38,550
Now inside the guard, when I showed the request, we were receiving the integer ID, which will be

27
00:01:38,550 --> 00:01:39,110
the order.

28
00:01:40,440 --> 00:01:47,120
So based on that, we will retrieve the order header from database, so I will add the order header

29
00:01:47,130 --> 00:01:52,530
using state and order header is equal to underscore unit of work.

30
00:01:52,920 --> 00:01:56,580
That order header that get pushed our default.

31
00:01:57,180 --> 00:01:59,490
We want to retrieve that based on the ID.

32
00:02:00,150 --> 00:02:06,090
So you right ID is equal equal to the ID that we received in the euro.

33
00:02:07,580 --> 00:02:10,430
So headed will be populated here.

34
00:02:10,910 --> 00:02:17,310
Next week, we'll have to check if the session indeed is not now, so we will have an if condition.

35
00:02:17,780 --> 00:02:21,000
And we will check if order had a diet session ID.

36
00:02:21,680 --> 00:02:22,580
It's not now.

37
00:02:23,030 --> 00:02:24,890
That means it has a session ID.

38
00:02:26,130 --> 00:02:31,680
Based on that, S.A.T., we need to validate if the payment was successful or not.

39
00:02:32,700 --> 00:02:39,270
So we will have to create a variable service is equal to near session service.

40
00:02:39,930 --> 00:02:43,830
We're going to have to act that using statement for Stripe Dot Checkout.

41
00:02:44,460 --> 00:02:48,300
Make sure not to use the billing portal or else it won't work.

42
00:02:49,050 --> 00:02:55,950
Once we create the session service, we have to create a session just like we did during checkout.

43
00:02:56,700 --> 00:03:04,370
Previously, we created a session that create that showed that inside the on post, we have service

44
00:03:04,370 --> 00:03:05,220
start create.

45
00:03:06,000 --> 00:03:08,550
This time we did not want to create a new service.

46
00:03:08,880 --> 00:03:10,950
We want to retrieve an existing one.

47
00:03:11,340 --> 00:03:13,020
So favorite, says service start.

48
00:03:13,020 --> 00:03:17,880
Get when we want to retrieve a session here we will have to pass.

49
00:03:17,880 --> 00:03:20,130
The order had a dart session ID.

50
00:03:21,120 --> 00:03:23,820
So based on that, it will retrieve the service.

51
00:03:24,720 --> 00:03:27,720
Make sure that this will be service and not the session.

52
00:03:28,290 --> 00:03:31,320
The session will get populated right here.

53
00:03:32,220 --> 00:03:37,590
Once we have the session here, we can check the payment status of that session.

54
00:03:38,040 --> 00:03:40,270
I already know what it should be.

55
00:03:40,290 --> 00:03:42,690
So I would just convert that to lower.

56
00:03:43,050 --> 00:03:45,120
And this should be equal to paid.

57
00:03:45,690 --> 00:03:49,110
If that is paid, that means that payment was successful.

58
00:03:50,010 --> 00:03:58,260
If the payment is successful and we want to update the order had a budget that is equal to static details,

59
00:03:58,710 --> 00:04:02,190
and the next add is that we have it status submitted.

60
00:04:04,770 --> 00:04:08,940
The value that we have inside submitted a submitted payment approved.

61
00:04:09,450 --> 00:04:11,640
This means that payment was approved.

62
00:04:12,420 --> 00:04:15,480
Once you update this, you will have to cut it off.

63
00:04:15,540 --> 00:04:16,620
Work about save.

64
00:04:17,370 --> 00:04:23,340
Now you might be thinking that we are saving things directly like this rather than using repository.

65
00:04:24,060 --> 00:04:30,030
If you want, you can create a custom method to just change the status of order and call that.

66
00:04:30,720 --> 00:04:36,660
Yet the unit after that save, it's working because when you retrieve something with get pushed our

67
00:04:36,660 --> 00:04:37,260
default.

68
00:04:37,620 --> 00:04:42,390
In that case, Entity Framework Code already tracks everything that is being done.

69
00:04:42,960 --> 00:04:47,430
So if you modify something in the order header, it is already tracking back.

70
00:04:48,120 --> 00:04:52,940
So when you hit the save here, it will automatically save those changes.

71
00:04:53,980 --> 00:05:00,280
Once the changes are saved, this means that order was created successfully in that case.

72
00:05:00,490 --> 00:05:03,340
Now it is safe to clear our shopping cart.

73
00:05:04,100 --> 00:05:10,960
So outside of the if condition, we can create a list of shopping cart, I will have to add to using

74
00:05:10,960 --> 00:05:15,260
statement for system that link and collection that generics.

75
00:05:16,270 --> 00:05:21,580
So on unit of work, we will cut our shopping cart to retrieve all the shopping cart.

76
00:05:21,730 --> 00:05:26,640
But user I.D. is equal to the user ID of this order header.

77
00:05:27,490 --> 00:05:34,150
We retrieve all of the shopping cart and we will take note of that shopping cart to remove range.

78
00:05:34,720 --> 00:05:38,020
We want to remove all of those shopping cart items.

79
00:05:39,290 --> 00:05:43,790
Once that is done, make sure to see if the changes aren't perfect.

80
00:05:44,240 --> 00:05:45,170
This looks good.

81
00:05:46,390 --> 00:05:51,430
Finally, the idea that we receive here, we will have to display that in the confirmation.

82
00:05:52,390 --> 00:05:58,990
So instead, page model here we can create a property of order it and we can order.

83
00:05:58,990 --> 00:06:04,690
It is equal to the ID that we received and the beach here.

84
00:06:05,110 --> 00:06:08,540
We can just display at models that are dividing.

85
00:06:09,710 --> 00:06:17,090
With that order, confirmation looks good, let me add a breaking point so that we can monitor our session

86
00:06:17,100 --> 00:06:19,550
servers and see how it works.

87
00:06:20,670 --> 00:06:24,600
Now, at this time, the order status should be updated successfully.

88
00:06:24,900 --> 00:06:31,140
So what I will do is have to go back to the database and delete all the other order header and details

89
00:06:31,140 --> 00:06:34,680
that we have because we don't care about those records.

90
00:06:35,160 --> 00:06:37,680
They were just going to test the scenarios.

91
00:06:38,760 --> 00:06:41,700
Now, let's go back here and create a new order.

92
00:06:45,260 --> 00:06:48,140
Let's add a few items to the shopping cart here.

93
00:06:49,560 --> 00:06:53,910
Let's go to Clark, modify some things for a fact.

94
00:06:54,42