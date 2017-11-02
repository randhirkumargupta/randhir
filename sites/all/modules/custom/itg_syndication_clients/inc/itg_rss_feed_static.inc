<?php

function itg_rss_feed_static_syndication() {
  genrate_static_indiatoday_event_main();
  genrate_static_indiatoday_versioncontrol_android();
  genrate_static_indiatoday_versioncontrol_iphone();
  genrate_static_indiatoday_contactus();
  genrate_static_indiatoday_ads_ad();
  genrate_static_indiatoday_aboutus();
}

function genrate_static_indiatoday_aboutus() {
  $xml = "<Root>
          <item>
          <id>1</id>
          <title>About Us</title>
          <website>India Today</website>
          <thumbimage/>
          <shortdescription/>
          <longdescription>
          <![CDATA[
          <p>India Today was launched in 1975. And in just a few years, it became the leading news magazine in the country. Now, with editions in five languages, it is the most widely-read publication in India-a position it has held for over a decade-with a readership of over 11 million (Source: IRS)</p><p>At present, India Today is published in Hindi, Tamil, Telugu and Malayalam. These editions deliver the same credibility, incisiveness and authority to our readers, that has become the hallmark of India Today. To keep pace with the diversifying interests of its affluent readers, the India Today Group has added 5 magazines to its value proposition - Simply, Aspire, Woman, Spice & Home.</p><p>In its online avatar, www.indiatoday.in brings you a daily connect with India's leading news magazine through special articles, blogs, columns, breaking news coverage and more. Also available on mobile handsets at m.indiatoday.in. The India Today Magazine is also available digitally across devices like the Kindle, iPad, Smartphones, Mac, Personal Computers,Windows phone and other tablets.</p>
          ]]>
          </longdescription>
          <weburl>
          <![CDATA[ http://indiatoday.intoday.in ]]>
          </weburl>
          </item>
          </Root>";
  $xml_path = 'public://indiatoday/aboutus.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

function genrate_static_indiatoday_ads_ad() {
  $xml = "<Root>
          <ads>
          <ad>
          <adimagesmall>
          http://media2.intoday.in/microsites/banners/nokia/AT_50x40.png
          </adimagesmall>
          <adimagelarge>
          http://media2.intoday.in/microsites/banners/nokia/AT_300x250.gif
          </adimagelarge>
          <adtext>Click for more</adtext>
          </ad>
          </ads>
          </Root>";
  $xml_path = 'public://samsungtv_it/ads/ad.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

function genrate_static_indiatoday_contactus() {
  $xml = "<Root>
          <item>
          <id>1</id>
          <title>Contact Us</title>
          <thumbimage/>
          <shortdescription/>
          <longdescription>
          <![CDATA[
          <p>THE INDIA TODAY GROUP<br />MEDIAPLEX<br />FC-8, SECTOR - 16A, <br />FILM CITY, <br />UTTAR PRADESH, NOIDA - 201301<br />Phone: +91-120-4807100<br />http://www.indiatodaygroup.com<br />Email:<span title='mailto:tech.support@intoday.com'>tech.support@intoday.com</span></p>
          ]]>
          </longdescription>
          <weburl/>
          </item>
          </Root>";
  $xml_path = 'public://indiatoday/contactus.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

function genrate_static_indiatoday_versioncontrol_iphone() {
  $xml = "<response>
        <content>
        <update_available>1</update_available>
        <latest_app_version>2.3</latest_app_version>
        <is_mandate>1</is_mandate>
        <previous_version_expired_on>2015-10-24</previous_version_expired_on>
        <reminder_frequency>2</reminder_frequency>
        <backend_version>v2</backend_version>
        </content>
        </response>";
  $xml_path = 'public://indiatoday/versioncontrol_iphone.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

function genrate_static_indiatoday_versioncontrol_android() {
  $xml = "<response>
          <content>
          <update_available>1</update_available>
          <latest_app_version>1.39</latest_app_version>
          <is_mandate>1</is_mandate>
          <previous_version_expired_on>2017-09-12</previous_version_expired_on>
          <reminder_frequency>2</reminder_frequency>
          <backend_version>v2</backend_version>
          </content>
          </response>";
  $xml_path = 'public://indiatoday/versioncontrol_android.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

function genrate_static_indiatoday_event_main() {
  $xml = "<xml>
          <event>
          <eventname>
          <event_type>cricket</event_type>
          <url>
          http://cricketlive.intoday.in/data/live-cric-updates.xml
          </url>
          <flag>1</flag>
          </eventname>
          <eventname>
          <event_type>event</event_type>
          <url>
          http://feeds.intoday.in/indiatoday/event-update.xml
          </url>
          <flag>0</flag>
          </eventname>
          </event>
          </xml>";
  $xml_path = 'public://indiatoday/event-main.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}
