<?php
$mobile = $_REQUEST['phone'];

$mobileMsg = 'Thank You for your interest. Download the Aaj Tak app bit.ly/ATAppMobLink for latest Hindi news, breaking news and much more.'; 

$sms_xml = file_get_contents('http://bulkpush.mytoday.com/BulkSms/SingleMsgApi?feedid=341284&username=9811264292&password=gggpp&Text='.urlencode($mobileMsg).'&To='.$mobile);
      
      if(strpos($sms_xml,'<CODE>')>0) {//SMS not sent retry 5 times times
            print 'no';
      } else {
            print 'yes';
         
      }

?>