<?php

/**
 * Function for generate static xml feed
 */
function itg_rss_feed_static_syndication() {
  genrate_static_indiatoday_event_main();
  genrate_static_indiatoday_versioncontrol_android();
  genrate_static_indiatoday_versioncontrol_iphone();
  genrate_static_indiatoday_contactus();
  genrate_static_indiatoday_ads_ad();
  genrate_static_indiatoday_aboutus();
  genrate_static_indiatoday_assembly_election_2015_photos();
  genrate_static_indiatoday_assembly_election_2015_videos();
  genrate_static_indiatoday_assembly_election_2015_stories();
  genrate_static_msn_stories_railway_budget();
  genrate_static_msn_stories_columns();
  genrate_static_assembly_election_2015_photos();
}

/**
 * Generate elections-16302-photos.xml feed
 */
function genrate_static_assembly_election_2015_photos() {
  $xml = <<<XML
    <Root>
<idsection>16302</idsection>
<section>elections</section>
<totalgalleries>5</totalgalleries>
<start_index>0</start_index>
<end_index>5</end_index>
<gallery>
<galleryid>16302</galleryid>
<title>
<![CDATA[
JD(U) supporters celebrate the Mahagathbandhans victory
]]>
</title>
<thumbimage>
<![CDATA[
http://media2.intoday.in/indiatoday/images/Photo_gallery/thumb_180_110815012708.jpg
]]>
</thumbimage>
<weburl>
<![CDATA[
http://indiatoday.intoday.in/gallery/bihar-elections-jdu-supporters-celebrate-the-mahagathbandhans-victory/1/16302.html
]]>
</weburl>
<create_date>2015-11-08T13:31:19+05:30</create_date>
</gallery>
</Root>
XML;
  $xml_path = 'public://elections/assembly_election_2015/elections-16302-photos.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Generate columns-msn.xml static feed
 */
function genrate_static_msn_stories_columns() {
  $xml = <<<XML
<rss xmlns:media="http://www.msn.com/en-in/" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">
<channel></channel>
</rss>
XML;
  $xml_path = 'public://msn/stories/columns-msn.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * function for generate static railway-budget-msn.xml
 */
function genrate_static_msn_stories_railway_budget() {
  $xml = <<<XML
<rss xmlns:media="http://www.msn.com/en-in/" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0"><channel><item><title><![CDATA[
You may have to pay more for rail journeys. Here's why
]]></title><link>
http://www.businesstoday.in/union-budget-2017-18/railway-budget-2017/union-budget-2017-18-you-may-pay-more-for-rail-journeys/story/245563.html
</link><pubDate>2017-02-02 14:32:55 IST</pubDate><modifiedDate>2017-02-02 14:32:55 IST</modifiedDate><guid>728331cd80412f9da6341d2ea59b64e3</guid><description><![CDATA[
"We will continuously endeavour to improve the Operating Ratio of 
 the Railways. The tariffs of Railways will be fixed, taking the costs, 
 quality of service, social obligations and competition from other forms 
 of transport into consideration," Jaitley said.
]]></description><content:encoded><![CDATA[
<p>If the country's youngsters want luxurious, speedy train journeys, then they have to be prepared to pay more. Seeking to justify the high rail fare in premium trains like Gatimaan Express as well as Rajdhani and Shatabdi trains, Finance Minister Arun Jaitley said that the tariff would be determined by the quality of service and competition from other modes of transport. </p><p>"We will continuously endeavour to improve the Operating Ratio of the Railways. The tariffs of Railways will be fixed, taking the costs, quality of service, social obligations and competition from other forms of transport into consideration," Jaitley said, while presenting the first rail budget merged with the General Budget. </p><p>Railways are in the process of introducing new luxury trains like Hamsafar and Tejas Express, which will be more expensive than normal trains. Also, the proposed bullet train and the high speed trains will incur higher cost. Jaitley also announced the withdrawal of service charges from tickets booked via IRCTC to promote cashless transaction. </p><p>{}</p><p>IRCTC is likely to lose about Rs 500 crore a year due to this. Jaitley also said that booking of railway tickets via cashless transactions has gone from 58 per cent to 68 per cent. </p><p>Faced with a series of derailments, the Railways got a much needed separate fund for safety upgradation of the rail network with the budget proposing an outlay of Rs 1 lakh crore that will cover the upgradation of tracks and signaling, besides the elimination of unmanned level crossings. </p><p>The budget announced listing three railways PSUs - IRCTC, IRFC and IRCON - in share markets, as well as converting 500 stations into disabled-friendly ones. All the coaches will be equipped with bio-toilets by 2019, and Railways will also have a Clean my coach app. </p><p>Prabhu also mentioned the joint participation with several state governments to execute rail projects, adding that the bidding process for developing 23 stations will begin soon. It was also proposed to feed about 7,000 stations with solar power in the medium term. While this has already been done in 300 stations, work on 2,000 railway stations, as a part of the 1000 MW solar mission, will begin soon. </p><p>The Railway Budget, merged with the General Budget 2017-18, also provides for the commissioning of new railway lines of 3,500 km against 2,800 km in 2016-17. </p><p>Jaitley also announced the plan size for the next fiscal for the Railways at Rs 1,31,000 crore as against Rs 1.21 lakh crore last year. He proposed the creation of 'Rashtriya Rail Sanraksha Kosh' (National Rail Safety Fund) with a corpus of Rs 1 lakh crore.</p><p>{}<br /></p>
]]></content:encoded><keywords><![CDATA[
Union Budget 2017-18, speedy train journeys, rail fare, Gatimaan Express, Rajdhani, Shatabdi trains, Finance Minister, Arun Jaitley
]]></keywords><media:content url="http://media2.intoday.in/btmt/images/stories/railway-ap21_660_020217013854.jpg" type="image/jpg"/><media:thumbnail url="http://media2.intoday.in/btmt/images/stories/railway-ap21_80_020217013854.jpg" type="image/jpg"/><category>railway-budget</category></item></channel></rss>
XML;

  $xml_path = 'public://msn/stories/railway-budget-msn.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function is for elections-stories.xml feed
 */
function genrate_static_indiatoday_assembly_election_2015_stories() {
  $xml = <<<XML
    <Root><idsection>264</idsection><section>Elections</section><totalarticle>25</totalarticle><start_index>0</start_index><end_index>25</end_index><item><storyid>527639</storyid><headline><![CDATA[
Nitish sworn in as Bihar CM, Lalu's sons join his jumbo ministry
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-20T16:58:43+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Nitish's swearing-in ceremony organised at the sprawling Gandhi Maidan 
 in Patna was a show of strength for the anti-BJP forces.
]]></kicker><body><![CDATA[
<p>Janata Dal-United leader (JD-U) leader Nitish Kumar, who led the grand alliance or Mahagathbandhan comprising of JD-U, RJD and Congress to a spectacular victory in the Assembly election, took oath as Bihar chief minister for the fifth time on Friday.</p><p><u>Also Read: Nitish Kumar's swearing in ceremony: As it happened</u></p><p>Nitish's swearing-in ceremony organised at the sprawling Gandhi Maidan in Patna was a show of strength for the anti-BJP forces as leaders like Congress vice president Rahul Gandhi, former PM HD Devegowda, Trinamool Congress supremo and West Bengal CM Mamata Banerjee, Delhi CM Arvind Kejriwal attending the function along with scores of other leaders.</p><p><u>Also Read: Lalu's son, Tej Pratap, fumbles twice during swearing-in</u><br /></p><p>The galaxy of leadersÂ  also included Tarun Gogoi, Virbhadra Singh, former Jammu and Kashmir chief minister Omar Abdullah and his father Farooq Abdullah. The Left was represented by CPI leaders Sitaram Yechury and D Raja. DMK leader M Karunaidhi's son son MK Stalin was also present during the oath taking function which lasted an hour.</p><p>Prime Minister Narendra Modi was also invited for Nitish's swearing-in ceremony, but the PM was represented by Union Minister Venkaiah Naidu.</p><p>The Samajwadi Party, however, decided not to attend the function. UP chief Minister Akhilesh Yadav and senior party leader Shivpal Yadav had confirmed their participation, but sources said that Shivpal Yadav called Nitish Kumar on Friday morning to express their inability to attend the ceremony. <br /><br />Lalu, Rabri get emotional as sons take oath as ministers</p><p>Both sons of RJD chief Lalu Prasad and former Bihar CM Rabri Devi - Tej Pratap and Tejaswi - took oath as ministers in Nitish's jumbo 28-man Cabinet. While Lalu's younger son Tejaswi, 26,Â  has been made Nitish's deputy. He will also look after the PWD and construction building ministries.Â Elder brother Tej Pratap, 28,Â has been given the responsibility of health and minor irrigation ministries.</p><p>Swearing-in turns into Patna Summit for anti-BJP forces</p><p>Nitish Kumar had broken his 17-year-old alliance with the BJP in 2013 after Narendra Modi was declared his party's prime ministerial candidate in the run-up to the 2014.</p><p>Lok Sabha election. The 2015 Bihar Assembly election saw anti-BJP forces joining hands against the BJP-led NDA. The combined might of RJD, JD-U and the Congress humiliating the BJP, which managed to win just 58 seats in the 243-seat Bihar Assembly.</p><p>Nitish's swearing-in ceremony in Patna on Friday was utilised by leaders of several anti-BJP parties to meet and probably discuss the possibility of a united front. </p><p>After the oath taking function, Nitish hosted a high tea for his guests at his official residence in Patna - 1 Anne Marg. Parties opposed to the BJP are likely to agree to work together in Parliament and evolve a common strategy. <u>In Pics: Who attended Nitish Kumar's high tea?</u><br /></p><p>Sources said the leaders informally conferred amongst themselves and agreed on working together in Parliament as a first step towards putting up a joint front against the BJP-led government at the Centre.</p><p>Gandhi Maidan - the centre of unique photo-ops</p><p>The huge media contingent covering the function at Gandhi had plenty to talk and write about. The Aam Aadmi Party (AAP) national convener and Delhi CM Arvind Kejriwal and RJD supremo Lalu Prasad hugged each other on the massive stage prepared for the event giving the camera persons an unique opportunity to click both the leaders in one frame. Political pundits also had much to talk about when Mamata Banerjee shook hands with arch-rival Yechury. <br /></p><br /> funfactsPortfolios of new Bihar ministers <ol><li>Tejaswi Yadav - Deputy CM, PWD and building construction minister </li><li>Tej Pratap - Health and minor irrigation minister</li><li>Abdul Bari Sidduui - Finance minister</li><li>Lalan Singh - Water resources minister</li><li>Ashok Chaudhary - Education minister</li><li>Vijender Yadav - Energy and commerce minister</li><li>Sharavan Kumar - Rural development minister</li><li>Madan saini - Food and civil supplies minister</li><li>Alok Mehta - Cooperative minister</li><li>Santosh Nirala - SC/ST minister</li><li>Abdul Gafoor - Minority affairs minister</li><li>Kapildev Kamat - Panchayati raj minister</li><li>Anita Devi - Tourism minister</li><li>Vijay Prakash - Labour resources minister</li><li>Ram Vichra Rai - Agriculture minister</li><li>Madan Mohan Jha - Revenue and land development minister</li><li>Awdhesh Kumar Singh - Veterinary minister</li></ol>funfacts <p>&nbsp;</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath_1_story_180_112015060331.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath_1_story_305_112015060331.jpg
</highres><caption><![CDATA[
Nitish's swearing-in ceremony in Patna on Friday was utilised by leaders of several anti-BJP parties to meet and probably discuss the possibility of a united front. (Pic:ANI)
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/nitish-sworn-in-as-bihar-cm-lalus-sons-join-his-jumbo-ministry/1/527639.html
]]></weburl></item><item><storyid>527527</storyid><headline><![CDATA[
Mamata's support to Nitish gets her saree from Rabri Devi
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-20T15:16:33+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
RJD chief Lalu Prasad Yadav's wife Rabri Devi has gifted West Bengal Chief Minister Mamata Banerjee a saree.
]]></kicker><body><![CDATA[
<p>RJD chief Lalu Prasad Yadav's wife Rabri Devi has gifted West Bengal Chief Minister Mamata Banerjee a saree during Nitish Kumar's oath-taking ceremony on Friday. The Trinamool Congress (TMC) supremo shared the dais with other political arch-rivals at the ceremony to display a picture of unity opposed to the BJP.</p><p>On Thursday, the Trinamool Congress said that Mamata's presence would be a sign of 'protest against authoritarian attitude of the Centre'.</p><p>The Mamata-Nitish duo have always shared an easy relationship. The TMC chief had left no stone unturned in showing her loyalty to the Grand Alliance. Mamata had urged the people of Bihar to vote for the alliance and re-elect Nitish Kumar as the chief minister of the state. TMC leader and state urban development minister Firhad Hakim had also said that there was a need to defeat the communal forces in the country.</p><p>Congratulating Nitish on Twitter over his victory, Mamata had termed the Grand Alliance win as the defeat of 'intolerance'.</p><p>"Congratulations Nitish Kumarji, Laluji and your full team, and all my Bihar brothers and sisters," the Trinamool Congress tweeted. This, she said, was a "victory of tolerance, defeat of intolerance," she had tweeted.</p><p>On the other side, the Janata Dal (United) has always reciprocated Mamata's efforts towards the party. Last week, the JD(U) had extended its support to the Bengal Chief Minister in her fight against the BJP.</p><p>Nitish Kumar had congratulated the TMC supremo for her party's victory in West Bengal's by-elections. </p><p></p><p>Former Prime Minister H D Deve Gowda and chief ministers of nine states, including Arvind Kejriwal, Union ministers and senior BJP leaders Venkaiah Naidu and Rajiv Pratap Rudy attended Nitish's oath taking ceremony at Patna's Gandhi Maidan</p><p>PM Narendra Modi was also invited by Nitish to attend the event. Bihar JD(U) president Basistha Narayan Singh said inviting the Prime Minister was a political etiquette and it was now on him whether to come or not. On being asked about the invitation, Bihar BJP vice president Sanjay Mayukh said that PM due to his "prior fixed programmes" might not be able to attend the ceremony.</p><p><br /></p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/mamata_story_180_112015031633.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/mamata_story_305_112015031633.jpg
</highres><caption><![CDATA[
Mamata Banerjee with Lalu Prasad and Arvind Kejriwal at the oath-taking ceremony
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/mamata-support-to-nitish-gets-her-saree-from-rabri-devi/1/527527.html
]]></weburl></item><item><storyid>527476</storyid><headline><![CDATA[
Lalu's son Tej Pratap, fumbles twice during swearing-in
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-20T14:41:27+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Bihar Governor Ram Nath Kovind had to interrupt RJD chief Lalu Prasad's 
 elder son Tej Pratap twice and asked him to repeat his oath as he fumbled a 
 word.
]]></kicker><body><![CDATA[
<p>Bihar Governor Ram Nath Kovind had to interrupt RJD chief Lalu Prasad's elder son Tej Pratap twice and ask him to repeat his oath as he fumbled a word.</p><p>"It's apekshit(expected), not upekshit (neglected)," Kovind told Tej Pratap, who represents the Mahua contituency. The 28-year-old MLA was stopped again after he made another mistake while taking oath. Tej Pratap trounced HAM's Ravindra Ray, also a rebel from the JD(U), by 28,155 votes in Mahua.</p><p>Tej Pratap's younger brother, Tejaswi, who is likely to be made Nitish Kumar's deputy, read his oath flawlessly. Tejashwi won the Raghopur Assembly seat by a margin of 22,733 votes.</p><p>A jumbo 28-man Cabinet took oath as ministers at Patna Gandhi Maidan on Friday.</p><p>List of ministers who took oath:</p><p>Nitish Kumar - Chief Minister, Home, General Administration, Cabinet Secretariat,<br />Vigilance, Information and Public Relations&nbsp;<br />Tejashwi Yadav- Deputy Chief Minister, Road construction, Building construction,<br />Backward and Extremely Backward Welfare&nbsp;<br />Tej Pratap Yadav - Health, Water resources, Environment and Forest&nbsp;<br />Abdul Bari Siddiqui - Finance&nbsp;<br />Bijendra Pratap Yadav - Power, Commerce and Tax&nbsp;<br />Rajiv Ranjan Singh alias Lallan Singh - Water Resources, Planning and Development<br />Ashok Choudhary - Education, Information and Broadcasting<br />Sharawan Kumar - Rural Development, Parliamentary Affairs&nbsp;<br />Jay Kumar Singh - Industries, Science and Technology&nbsp;<br />Alok Kumar Mehta - Cooperative Department&nbsp;<br />Chandrika Rai - Transport&nbsp;<br />Awdesh Kumar Singh - Animal Husbandry and Fisheries&nbsp;<br />Krishna Nandan Prasad Verma - Public health (Lok Swasthya Abhiyantran Vidhi)&nbsp;<br />Maheshwar Hazari - Urban Development&nbsp;<br />Abdul Jalil Mastan - Registration, Excise and Prohibition Ministry&nbsp;<br />Ram Vichar Rai - Irrigation&nbsp;<br />Sheo Chander Ram - Youth, Arts and Culture&nbsp;<br />Dr Madan Mohan Jha - Treasury and Land Development&nbsp;<br />Shailesh Kumar - Rural Work&nbsp;<br />Kumari Manju Verma - Social Welfare&nbsp;<br />Santosh Kumar Nirala - SC and ST Welfare&nbsp;<br />Abdul Gafoor - Minority Welfare&nbsp;<br />Chandrashekhar - Disaster Management&nbsp;<br />Khurshid alias Firoz Ahmad - Sugarcane Industries&nbsp;<br />Muneshwar Chaudhary - Mining&nbsp;<br />Madan Sahni - Food and Consumer Protection&nbsp;<br />Kapildeo Kamat - Panchayati Raj&nbsp;<br />Anita Devi - Tourism <br />Vijay Prakash - Labour Department<br />&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/tej-pratap_story_180-2_112015031914.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/tej-pratap_story_305_112015031914.jpg
</highres><caption><![CDATA[ Tej Pratap at the oath ceremony ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/tej-pratap-lalu-son-fumbles-asked-to-repeat-oath-twice-by-governor/1/527476.html
]]></weburl></item><item><storyid>527355</storyid><headline><![CDATA[
Live updates: Nitish sworn in as Bihar CM, Lalu's sons join his Cabinet
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-20T11:31:35+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Nitish Kumar&nbsp;took oath as Bihar Chief Minister for the fifth time on Friday. Leaders from across the country attended the function at Patna's Gandhi Maidan.
]]></kicker><body><![CDATA[
<p>Nitish Kumar took oath as Bihar Chief Minister for the fifth time on Friday. Both sons of RJD Lalu Prasad Tej Pratap and Tejaswi also took oath as minister in the Nitish Cabinet. According to sources, Lalu's younger son Tejaswi, 26, will be given the Deputy Chief Minister's chair.</p><p>Here are the live updates:&nbsp;</p><ul><li>Congress vice-president Rahul Gandhi reaches Gandhi Maidan, meets Lalu Prasad and other leaders present on the stage.</li><li>Read: Lalu's son, Tej Pratap, fumbles twice during&nbsp; swearing-in </li><li>This is a very important visit. Nitish ji has created history. Bihar election has brought in important change in national politics. (PM Narendra) Modi has a reason to rethink his policies: Former J-K Chief Minister Omar Abdullah.&nbsp;</li><li>&nbsp;The combination of Nitish and Lalu has worked. We are here for a purpose: Sitamram Yechury &nbsp;</li><li>&nbsp;RJD leader Abdul Bari Siddiqui takes oath as minister in Nitish's Cabinet.</li><li>&nbsp;Lalu Prasad's elder son Tej Pratap takes oath&nbsp;as minister.</li><li>&nbsp;Lalu's younger son Tejaswi Yadav takes oath as minister.</li><li>&nbsp;Both&nbsp;sons of Lalu Prasad -&nbsp;Tejaswi and Tej Pratap -&nbsp;included in Nitish's Cabinet.</li><li>&nbsp;Nitish Kumar takes oath as Bihar Chief Minister for the fifth time. This will be Nitish's third straight term as CM.&nbsp;</li><li>&nbsp;Nitish Kumar reaches Gandhi Maidan.&nbsp;</li><li>&nbsp;RJD chief Lalu Prasad and former&nbsp;Chief Minister Rabri Devi&nbsp;reach Gandhi Maidan.&nbsp;</li></ul><p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;List of ministers who will take oath: </p><ul><li>JD(U): Nitish Kumar, Kapil Dev Kamat, Bijeder Prasad Yadav, Madan Saini, Lalan Singh, Jai Kumar Singh, Shravan Kumar, Maheshwar Hajari, Shailesh Kumar, Krish Nandan Verma, Manju Verma, Khurshed Alam </li><li>RJD: Tejaswi Yadav, Tej Pratap, Abdul Bari Siddqui, Alok Mehta, Anita Devi, Shiv Chandra Ram, Chandrika Rai, Ram Vichar Rai, Chandra Sekhar, Vijay Praksh, Abdul Gaffur, Muneshwar Choudhary</li><li>Congress: Ashok Choudhary, Madan Mohan Jha, Awdhesh Singh, Abdul Jalil Mastan</li><li>Lok&nbsp;Janshakti Party (LJP) chief and Union minister Ram Vilas Paswan has said that the NDA is not worried over the meetings of anti-BJP leaders on the sidelines of Nitish's oath taking ceremony. "They all are scared of (Narendra) Modi's popularity.&nbsp;I don't think the alliance between Nitish and Lalu will last,"&nbsp;Paswan said.
 
 <block class="twitter-tweet" lang="en"><p>Thank you for all those who made time for the swearing in ceremony. Will be at Gandhi Maidan by 1PM.</p> Nitish Kumar (@NitishKumar) November 20, 2015</block><script src="//platform.twitter.com/widgets.js" charset="utf-8" async=""></script>
 
 &nbsp;&nbsp;&nbsp;&nbsp;</li><li>Former Delhi CM Sheila Dixit and Himachal Pradesh CM Virbhadra Singh have arrived in Patna.&nbsp;</li><li>Congress MLA Abdul Zalil Mastan is to take oath in Patna but his flight has been diverted to Ranchi due to poor visibility. <br />&nbsp;</li><li>The function is likely to get delayed as bad weather in Patna has delayed flights of many VVIPs. All flights at the Patna airport have been delayed due to fog. The visibility at the airport is only 800mts and the minimum requirement is 1200mts.</li><li>In a latest development the Samajwadi Party has decided not to attend the function. UP chief Minister Akhilesh Yadav and senior party leader Shivpal Yadav had confirmed their participation, however, sources said that Shivpal Yadav called Nitish Kumar on Friday morning to express their inability to attend the ceremony.&nbsp; </li><li>JD(U) MLA Shyam Rajak and former minister will not attend the oath taking ceremony as his name is not in the list of probable ministers. Rajak is said to said to be miffed over being dropped from Nitish's new Cabinet and is likely to boycott the function.</li><li>Lots of one to one meetings taking place between leaders who are attending the swearing in ceremony. DMK leader MK Stalin will call on West Bengal CM Mamata Banerjee. Late last night, he called on Sharad Yadav and Lalu Yadav. Sharad Pawar and Praful Patel are likely to call on Mamta Banerjee soon after they arrive in Patna around noon. All the leaders will then meet at the high tea being hosted by Bihar CM Nitish Kumar after the swearing-in ceremony. <block class="twitter-tweet" lang="en"><p>Sharing the names of some esteemed guests attending the oath taking ceremony of the new Govt of Bihar on 20.11.2015 pic.twitter.com/mtHBjY3kEq</p> Nitish Kumar (@NitishKumar) November 18, 2015</block><script src="//platform.twitter.com/widgets.js" charset="utf-8" async="" mce_src="//platform.twitter.com/widgets.js"></script></li><li>Other veterans coming down to Patna for the event include Maharashtra strongman and Nationalist Congress Party leader Sharad Pawar and his party man and former Union minister Prafulla Patel. National Conference leaders Farooq Abdullah and his son, former Chief minister of Jammu and Kashmir Omar Abdullah will also grace the occasion.</li><li>From Congress vice-president Rahul Gandhi and former prime minister H D Deve Gowda to chief ministers of nine states, including Mamata Banerjee and Arvind Kejriwal and a galaxy of the leaders from the different parties will grace the event.</li><li>Top leaders from across the country will be in Patna to attend Nitish's swearing-in ceremony.<br /></li></ul><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish_cm_180_112015031500.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish_cm_305_112015031500.jpg
</highres><caption><![CDATA[
Nitish Kumar takes oath as Bihar CM for the fifth time.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/live-nitish-kumars-swearing-in-ceremony-fog-delays-flights-of-vvips/1/527355.html
]]></weburl></item><item><storyid>526399</storyid><headline><![CDATA[ Bihar shadow falls over Cabinet rejig ]]></headline><credit><![CDATA[ Kumar Vikram ]]></credit><date>2015-11-19T03:59:18+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Sources said the reshuffle might witness dropping of some under-performers as the government wants to focus mainly on its development agenda ahead of polls in various states, including Uttar Pradesh.
]]></kicker><body><![CDATA[
<p>Expected Cabinet reshuffle of the Modi government might see the imprint of the Bihar poll debacle. Sources said the reshuffle might witness dropping of some under-performers as the government wants to focus mainly on its development agenda ahead of polls in various states, including Uttar Pradesh. According to party sources, weaknesses and strength of the ministers will be assessed besides the Bihar polls performance.</p><p>Also read: Jaitley-Rahul meet likely to boost govt's GST hope </p><p>"Price rise of essential commodities is one of the main concerns of the government. Ministers who failed to perform as per the expectation might be dropped. Moreover, ministers who are found indulging in unnecessary remarks leading to the embarrassment of the party as well of the government will also be under the scanner," said a party insider. Many ministers have led to the embarrassment of the government and party with their remarks on the Dadri killing, the killing of Dalits in Haryana and the beef controversy - which grabbed unnecessary limelight during the Bihar polls.</p><p>Apart from this, results of Bihar polls will also have its imprint on the Cabinet rejig. Many Union ministers were given responsibility in their respective regions in Bihar during the polls and barring a few, most failed to show results. Even as the senior leadership is of the view that no individual is responsible for the defeat, however, role of senior ministers in the poll management will also be counted, said a source.</p><p>Ministers, including Radha Mohan Singh, Rajiv Pratap Rudy, Ravi Shankar Prasad, Ram Vilas Paswan, Upendra Kushwaha, Ram Kripal Yadav, and Dharmendra Pradhan camped in Bihar for about a month during the assembly elections. However, barring Union Agricultural Minister Radha Mohan Singh, all the ministers have lost majority of seats in their areas. Party registered victory in eight seats in East Champaran where Radha Mohan Singh was camping. Party could only bag two seats from the areas under ministers like Rajiv Pratap Rudy, Ram Vilas Paswan and Giriraj Singh.</p><p>Performances of Kushwaha and Yadav were not better. Communications Minister Ravi Shankar Prasad spent a considerable time in Bihar amidst the issue of call drops. Pradhan and Ananth Kumar were monitoring the poll preparations. Even as senior leaders have made this clear time and again that the Bihar verdict is not a referendum on PM Modi's governance stewardship, but, a party leader said the reshuffle will be an opportunity for a further course correction.</p><p>Party insiders claimed that organisational changes are also expected and some ministers from the Cabinet might be given responsibility of the organisation considering the upcoming state polls. A party leader said the reshuffle might see induction of more faces from UP due to the upcoming state polls and dropping of a few ministers from Bihar. "The PM will send out a strong message to the leaders, particularly to underperformers, through this reshuffle," said the leader.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bihar-polls,-veggie-price,lokayukta-4_180_111915093951.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bihar-polls,-veggie-price,lokayukta-4_305_111915093951.jpg
</highres><caption><![CDATA[ BJP leader Ravi Shankar Prasad. ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-shadow-falls-over-cabinet-rejig/1/526399.html
]]></weburl></item><item><storyid>525696</storyid><headline><![CDATA[
Naidu, Rudy to attend Nitish Kumar's swearing-in ceremony
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-18T15:38:43+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Nitish also extended his invitation to Prime Minister Narendra Modi for the oath taking ceremony, which will take place at Gandhi Maidan at 2 pm on November 20.
]]></kicker><body><![CDATA[
<p>Union ministers and senior BJP leaders Venkaiah Naidu and Rajiv Pratap Rudy will attend Bihar Chief Minister designate Nitish Kumar's swearing in ceremony on Friday.</p><p>Nitish also extended his invitation to Prime Minister Narendra Modi for the oath ceremony, which will take place at Gandhi Maidan at 2 pm on November 20.</p><p>Also read: Anti-Modi forces to unite at Nitish's swearing-in event </p><p>With the four-day Chhath festival ending Wednesday, Kumar telephoned prominent leaders personally to invite them for the swearing-in ceremony of the new government.</p><p>Bihar JD(U) president Basistha Narayan Singh said inviting the Prime Minister was a political etiquette and it was now on him whether to come or not.</p><p>Also Read: Sonia, Kejriwal, Mamata to attend Nitish Kumar's oath taking ceremony </p><p>On being asked about the invitation, Bihar BJP vice president Sanjay Mayukh said that PM due to his "prior fixed programmes" might not be able to attend the ceremony.</p><p>He said Parliamentary Affairs Minister Venkaiah Naidu and Minister of State (Independent Charge) Rajiv Pratap Rudy would represent the Union government at the swearing-in function.</p><p>The PM had congratulated Kumar on the day of the poll results on November 8 over the grand secular alliance's massive victory in Bihar.</p><p>The sources in CMO said Kumar had also telephoned Union Home minister Rajnath Singh, Finance Minister Arun Jaitley, External Affairs Minister Sushma Swaraj and other central ministers and invited them for the oath ceremony.</p><p>State Congress President Ashok Choudhary told PTI that party vice president Rahul Gandhi in all likelihood would attend the swearing-in function.</p><p>Rahul had played an important role in cementing bonds between three parties JD(U), RJD and Congress and also in naming Kumar the CM face of the grand secular alliance. He had addressed eight rallies in favour of secular alliance candidates during the poll campaign.</p><p>Chief Ministers of other states like Mamata Banerjee, Arvind Kejriwal, Tarun Gogoi and Akhilesh Yadav are expected to attend the ceremony to display a picture of unity among parties opposed to BJP.</p><p>Samajwadi Party MP from Mainpuri Tej Pratap Yadav, who is Patna in connection with Chhath observed by his mother-in-law Rabri Devi, confirmed that Yadav would attend the ceremony.</p><p>Kumar and RJD chief Lalu Prasad wish to make the oath ceremony a big event by bringing together leaders of different parties which are opposed to BJP.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath_180_111815033843.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath_305_111815033843.jpg
</highres><caption><![CDATA[ Bihar Chief Minister designate Nitish Kumar ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/venkaiah-naidu-rajiv-pratap-rudy-to-attend-nitish-kumars-swearing-in-ceremony/1/525696.html
]]></weburl></item><item><storyid>524580</storyid><headline><![CDATA[
Challenge ahead for Nitish as Bihar sees rise in crime
]]></headline><credit><![CDATA[ Giridhar Jha ]]></credit><date>2015-11-17T06:14:25+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
A surge in crime rate has been witnessed in Bihar in the wake of the 
 massive victory of the Grand Alliance in the recent Assembly elections.
]]></kicker><body><![CDATA[
<p>A surge in crime rate has been witnessed in Bihar in the wake of the massive victory of the Grand Alliance in the recent Assembly elections, throwing a big challenge to chief minister-elect Nitish Kumar, who is due to take oath in Patna on Friday.</p><p>A fertiliser trader Harishankar Singh was kidnapped at gun point while he was on a morning walk at the railway station at Panchrukhi in Siwan district on Sunday.</p><p>Eyewitness told police that Singh was accosted by six armed criminals, who forcibly took him away in a vehicle. Angry over the incident, the locals blocked the national highway as well as the railway tracks disrupting the vehicular and train traffic for several hours.</p><p>Demanding immediate recovery of the abducted businessman, the mob also resorted to arson.</p><p>The cops brought the situation under control after reassuring the people that Singh would be safely recovered. The police subsequently conducted raids at several places but had not recovered him so far.</p><p>The trader's abduction took place a day after a contractor was gunned down in Muzaffarpur district over tender rivalry. On Saturday morning, armed assailants on a motorcycle fired at Dharmendra Yadav from point-blank range at 5:30 am near Sherna village under Kanti police station.</p><p>The 32-year-old victim, who was a railway contractor at Kanti, died on the spot. Irate mob torched a police vehicle and an eatery in protest against the incident. The mob also blocked the national highway, railway lines and assaulted some cops forcing the local policemen to open fire in the air. A police rifle was also looted in the incident which was subsequently recovered.</p><p>The police suspected the killing to be the work of a gang headed by a jailed criminal allegedly over railway tenders. In another incident in Katihar district on Friday night, a liquor trader Shambhu Nayak was shot dead while he was returning home after closing his shop.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/saeed,-nitish-7_180_111715083936.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/saeed,-nitish-7_305_111715083936.jpg
</highres><caption><![CDATA[
People block railways in protest against the recent abduction of a trader in Bihar.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/challenge-ahead-for-nitish-as-bihar-sees-rise-in-crime/1/524580.html
]]></weburl></item><item><storyid>523686</storyid><headline><![CDATA[
If speaking truth is revolt then I am a rebel: Shatrughan Sinha
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-15T20:23:03+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
BJP MP Shatrughan Sinha fired fresh salvo saying he has done nothing to be sidelined and ignored by the party.
]]></kicker><body><![CDATA[
<p>Continuing his tirade against the party leadership, BJP MP Shatrughan Sinha fired fresh salvo saying he has done nothing to be sidelined and ignored by the party. Speaking to reporters in Nagpur, the disgruntled leader reiterated that he still is a loyal worker of the BJP.</p><p>"I have already said whatever I had to. Now, the seniors are speaking on matters facing the party. Was I wrong in saying that dal price rise should be controlled? If speaking truth is considered as revolt, then yes, I am a rebel," the Patna Sahib MP said amid reports that the BJP may take strict action against him soon for "anti-party activities". The axe is also likely to fall on other two Bihar BJP MPs RK Singh and Bhola Singh.</p><p>The actor-turned-politician, who had been sulking after he was left out of the Bihar Assembly election campaign, said it was because of the "aggressive campaigning" by Prime Minister Narendra Modi that BJP fetched 53 seats. Also Read: Ignored in Bihar poll, Shatrughan Sinha says 'Teri mehfil mein lekin, hum na honge' <br /></p><p>Sinha also said that Bihar voters had understood that the announcement of economic package by Modi was a "poll gimmick".</p><p>"All the credit goes to Modiji for the number seats won by BJP in Bihar and there should not be any doubt about it," Sinha said earlier in the day while taking a jibe at the PM.</p><p>According to reports, BJP's Bihar unit has conveyed to the party leadership in Delhi that it was important to take action these three Lok Sabha MPs as they worked to dent party's chances in the just concluded Assembly election.</p><p>Unless action is taken against these leaders, who caused extensive damage to the party in the crucial election, discipline would become a major issue within the party, sources d the state leadership telling top BJP leaders. Also Read:&nbsp; The issue of Bihari vs Bahari settled now, says Shatrughan Sinha <br /></p><p>Begusarai MP Bhola Singh even went to the extent of working against the NDA nominees in the district, which he represents, sources said.</p><p>In the recently held elections to the 243-seat Bihar Assembly, the grand alliance won 178 seats, including RJD-80, JD(U)-71 and Congress-27.</p><p>Also Read: Kailash Vijayvargiya compares Shatrughan Sinha to dog chasing a car<br /><br />&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bjp_story_180_111515082601.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bjp_story_305_111515082601.jpg
</highres><caption><![CDATA[ BJP MP Shatrughan Sinha. Photo: PTI ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/if-speaking-truth-is-revolt-then-i-am-a-rebel-shatrughan-sinha/1/523686.html
]]></weburl></item><item><storyid>523322</storyid><headline><![CDATA[
Bihar: 7-point nischay on CM-designate Nitish Kumar's agenda
]]></headline><credit><![CDATA[ Giridhar Jha ]]></credit><date>2015-11-15T03:25:58+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Nitish Kumar, along with members of the new Council of Ministers, will 
 take oath at the historic Gandhi Maidan at 2 pm on November 20.
]]></kicker><body><![CDATA[
<p>Janata Dal (United) leader Nitish Kumar will take oath as the Bihar chief minister on November 20, making it the fifth time he would be sworn-in as the CM. Bihar Governor Ramnath Kovind on Saturday invited Nitish to form the next government in the state after he was elected the leader of the Grand Alliance legislature party at its joint meeting in Patna.</p><p>Nitish, along with members of the new Council of Ministers, will take oath at the historic Gandhi Maidan at 2 pm on November 20.</p><p>Accompanied by RJD president Lalu Prasad, JD(U) chief Sharad Yadav, senior Congress leader CP Joshi and other leaders, Nitish drove to Raj Bhawan to hand over the letter of the Grand Alliance to governor Kovind.</p><p>Also read: PM Modi, Arvind Kejriwal may attend Nitish Kumar's oath taking <br /></p><p>Emerging out of Raj Bhawan, Nitish said all the three parties would be part of the next government. He, however, did not reveal the size of the ministry, saying that it would be revealed only during the swearing-in ceremony. "The matter has already been finalised among the three parties," he said.</p><p>Underlining the unity among the Grand Alliance, Nitish said all its three constituents had shown a picture of harmony during its poll campaign.</p><p>"Our government would be run with similar unity. We will try to live up to the expectations of the people who have given us a decisive mandate with three-fourths majority," he said.</p><p>Also read: Sonia, Kejriwal, Mamata to attend Nitish Kumar's oath taking ceremony <br /></p><p>Spelling out the priorities of his government, he said it would continue to work on its agenda of justice with growth and rule of the law.</p><p>"The Grand Alliance has a common minimum programme which consists of my seven-point nischay (resolve). It will be implemented vigorously with mutual trust among the allies. After all, the people have given their approval of our development agenda," he said.</p><p>The JD(U) leader emphasised that the government would work for maintaining amity, harmony and brotherhood in the society. "I believe in seeking the cooperation of the Opposition to bring about consensus on development issues," he said, adding: "Regardless of the election campaign, I do not believe in making fun of the Opposition."</p><p>On being asked whether senior BJP leader LK Advani would be invited to the swearing-in ceremony, he said: "Several leaders are invited for such occasions. You will come to know who are being invited."</p><p>Earlier in the day, all the three parties held their legislature party meetings separately before converging on the Bihar legislature premises for a joint meeting which was presided over by JD(U)'s state president Vashishtha Narayan Singh.</p><p>Lalu's wife and former CM Rabri Devi proposed the name of Nitish as the leader of the Grand Alliance legislature party which was seconded by Congress leader CP Joshi. This was unanimously approved by the meeting attended by all the 178 newlyelected legislators of the alliance.</p><p>Talking on the occasion, Nitish said it was the responsibility of all the three parties to run the government well and send out a good message to the rest of the country. Lalu asked Nitish to run the government fearlessly.</p><p>Earlier, the outgoing JD(U) government, at its final Cabinet meeting, approved the proposal to dissolve the Assembly.</p><p>Nitish handed over a copy of the resolution of the Cabinet meeting to the governor who accepted his recommendation and asked him to continue as the caretaker chief minister till the formation of the next government.</p><p>The Grand Alliance had won 178 seats in the 243-member Bihar Assembly in the recent elections, leaving its main rival -National Democratic Alliance (NDA)-with only 58 seats.</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish---1_180_111515081235.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish---1_305_111515081235.jpg
</highres><caption><![CDATA[
RJD chief Lalu Prasad presents a bouquet to JD(U)'s Nitish Kumar in Patna on Saturday. (Photo: Sonu Kishan)
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-7-point-nischay-on-cm-designate-nitish-kumars-agenda/1/523322.html
]]></weburl></item><item><storyid>522794</storyid><headline><![CDATA[
After Bihar debacle, more voices of dissent rattle BJP
]]></headline><credit><![CDATA[ Kumar Vikram ]]></credit><date>2015-11-14T06:03:34+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Amid growing voices of dissent within the saffron brigade, senior BJP 
 leader and Union minister Nitin Gadkari on Friday denied that he had 
 suggested any disciplinary action against the party's old guards.
]]></kicker><body><![CDATA[
<p>Amid growing voices of dissent within the saffron brigade, senior BJP leader and Union minister Nitin Gadkari on Friday denied that he had suggested any disciplinary action against the party's old guards.</p><p>Meanwhile, BJP MP Manoj Tiwari joined several other party leaders in criticising his party's election strategy in Bihar and lauded the rival JD(U)-RJD-Congress alliance for having a better battle plan.</p><p>Tewari said the party failed to convince the people to vote for the BJP candidates in the keenly contested Bihar polls. "We failed to convince people to vote for the party at the Centre and earn maximum benefits. We clearly failed to convey our party agenda to the people of Bihar," he said.</p><p>Also read: Jaitley meets MM Joshi in bid to pacify BJP veterans <br /></p><p>BJP sources claimed that the group of veterans, including LK Advani, Murli Manohar Joshi and others, is apparently in no mood to relent and they may strike further. A party functionary said that the veterans are keenly observing all the developments.</p><p>"A section of leaders in the party is in support of these veterans. These leaders are expecting deliberations over the poor performance of the party in Bihar. It would be no surprise if more such attacks surface in coming days," a party source said.</p><p>Gadkari on Friday said the BJP central leadership is holding discussions with the veterans. "Party elders, including LK Advani and Murli Manohar Joshi, are our highly respected leaders and neither I nor any other party functionary has ever shown any disrespect to them. There was absolutely no question of anyone suggesting calling for an explanation from them and not the least demanding disciplinary action against them," said Gadkari in a statement.</p><p>The Union minister said reports in a section of the media, indicating that he suggested that disciplinary action be initiated against them are absolutely incorrect and misleading.</p><p>Bihar parliamentarian RK Singh also supported the veterans' demand that accountability be fixed for the drubbing. "Accountability has to be fixed. Review should be made of the election debacle. We need to find out what went wrong, who were responsible," he said.</p><p>A number of Bihar BJP MPs like Shatrughan Sinha, Hukumdev Narayan Yadav and Bhola Singh have criticised the party's campaign with the likes of Sinha and Singh drawing the party brass in their line of fire.</p><p>As the party grappled with the rumblings, Union minister M Venkaiah Naidu said the veterans should have raised their views at a party forum rather than going public. He asserted that the country and the party needed PM Narendra Modi's leadership, but said the BJP will take note of these views and concerns.</p><p>"Some of our senior leaders have raised certain issues. It would have been better if these issues were raised in a party forum rather than public, but still we will take note of these. We will discuss with all concerned. The parliamentary board has already decided to take it up with all the concerned and discuss the shortcomings that led to the defeat in Bihar. That has been the practice," Naidu said.</p><p>Responding to a question about the BJP veterans' open revolt, Naidu said, "They have not come out against Modi. They made a comment about the strategy in Bihar. They have not said even a single word against Modi. Only a section of media highlighted this as headlines," he said.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bjp-crisis---8_180_111415091328.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bjp-crisis---8_305_111415091328.jpg
</highres><caption><![CDATA[
Union ministers and senior BJP leaders Venkaiah Naidu (left) and Nitin Gadkari.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/after-bihar-debacle-more-voices-of-dissent-rattle-bjp/1/522794.html
]]></weburl></item><item><storyid>521602</storyid><headline><![CDATA[
Sincere Bihari Babu was kept away from Bihar campaign: Shatrughan
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-12T12:06:41+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
BJP MP Shatrughan Sinha on Thursday denied saying that the Bihar 
 election results could have been different if he had been projected the 
 party's CM candidate.
]]></kicker><body><![CDATA[
<p>BJP MP Shatrughan Sinha on Thursday denied saying that the Bihar election results could have been different if he had been projected the party's CM candidate.</p><p>Also Read | Kailash Vijayvargiya compares Shatrughan Sinha to dog chasing a car <br /></p><p>Sinha blamed the media and said on Twitter that it was the media who had created this impression.</p><block class="twitter-tweet" lang="en"><p>Media tried to create an impression that I had suggested that results cud've been different IF I WAS CM CANDIDATE. I have never said this.</p>&amp;; Shatrughan Sinha (@ShatruganSinha) November 12, 2015</block><script src="//platform.twitter.com/widgets.js" async="" mce_src="//platform.twitter.com/widgets.js" charset="utf-8"></script><p>Sinha took another shot at the BJP, saying that despite his sincerity, efforts and good intentions, the 'Bihari Babu' had been kept away from campaigning. </p><block class="twitter-tweet" lang="en"><p>Despite sincerity, efforts &amp; intention BihariBabu was kept away from campaigning for my people. My friends, voters&amp;supporters were let down.</p>&amp;; Shatrughan Sinha (@ShatruganSinha) November 12, 2015</block><script src="//platform.twitter.com/widgets.js" async="" charset="utf-8"></script><p>He also emphasised his popularity among voters by saying that he had come through the support of masses and won 2 Lok Sabha elections with record margin.</p><block class="twitter-tweet" lang="en"><p>I am not a Rajya Sabha MP. I've come through the support of masses and won 2 Lok Sabha elections with record margin. I have a support base!</p>&amp;; Shatrughan Sinha (@ShatruganSinha) November 12, 2015</block><script src="//platform.twitter.com/widgets.js" async="" charset="utf-8"></script><p>Sinha said that now that the Bihar elections had been lost, the party must focus on fixing responsibility for the defeat.</p><block class="twitter-tweet" lang="en"><p>Nonetheless, now that the verdict is out and we're saddened by this humiliating defeat, we should not run away from fixing responsibility.</p>&amp;; Shatrughan Sinha (@ShatruganSinha) November 12, 2015</block><script src="//platform.twitter.com/widgets.js" async="" charset="utf-8"></script><p>Sinha's remarks come close on the heels of veteran leaders LK Advani, Murli Manohar Joshi, Shanta Kumar and Yashwant Sinha raising a banner of revolt against the leadership of Prime Minister Narendra Modi in the wake of Bihar debacle, saying the party has been "emasculated" in the last one year and was being "forced to kow-tow to a handful". The veterans had demanded a thorough review of the debacle. <br /></p><p>After the results, Sinha met chief minister Nitish Kumar to congratulate him on his impressive win. The Bollywood veteran said that Nitish Kumar was a successful, tried and tested chief minister who was the most respectable after former West Bengal chief minister Jyoti Basu.</p><p>Also Read | As BJP mulls action against him, Shatrughan meets Nitish Kumar <br /></p><p>BJP national general secretary Kailash Vijayvargiya had compared Sinha with a dog. "A dog walking under a car gets an impression that the car is moving because of him," the controversial BJP leader said while responding to a question regarding Shatrughan Sinha's open criticism of party's strategy during Bihar Assembly election.</p><p>The RJD emerged as the single largest party with 80 assembly seats, followed by the JD-U with 71 and the Congress with 27.</p><p>The Mahagathbandhan won 178 seats in Bihar, a commanding two-third majority in the 243-member assembly. The Bharatiya Janata Party and its allies had to settle for a mere 58 seats.</p><p>The victory of the Grand Alliance brought both the RJD and the Congress back on the centre-stage of Bihar politics with a bang. The victory left Lalu, whose party had won only 22 seats in the 2010 assembly elections, ecstatic.</p><p>The victory also gave a fresh lease of life to the Congress which had been struggling to regain its toehold in the state for several years. The party came up with its best performance in an assembly election in 20 years by winning 27 out of 41 seats.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/shatrughan-sinha_story_180_111215121602.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/shatrughan-sinha_story_305_111215121602.jpg
</highres><caption><![CDATA[ BJP MP Shatrughan Sinha ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bjp-mp-shatrughan-sinha-denies-cm-candidate-remark/1/521602.html
]]></weburl></item><item><storyid>521360</storyid><headline><![CDATA[
Process for govt formation to start on November 14, says Nitish Kumar
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-11T16:01:30+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Nitish Kumar said the formal process for formation of government in Bihar will start November 14 onwards.
]]></kicker><body><![CDATA[
<p>Chief Minister Nitish Kumar on Tuesday said the formal process for formation of government in Bihar will start November 14 onwards, when the state Cabinet will meet and recommend the dissolution of the present House.</p><p>A legislature party of the Grand Alliance will be held in the afternoon of November 14 to elect a new leader and decide the date and venue for the oath-taking ceremony, Kumar told reporters after emerging from Raj Bhawan, where he had gone to greet Governor Ram Nath Kovind for Diwali, PTI reported.</p><p>ALSO READ - BJP MP Shatrughan Sinha reaches Bihar CM residence in Patna to meet Nitish Kumar </p><p>Kumar said that after Saturday's legislature party meeting, the alliance would formally stake claim to forming the government.</p><p>To a question regarding the possibility of an RJD leader becoming Deputy Chief Minister, Kumar was non-committal and said merely that "everything will be told to you in time... why this anxiety before time?"</p><p>Speculation is rife in political corridors that somebody from Lalu Prasad's family could be made Deputy Chief Minister.</p><p>ALSO READ - Nitish Kumar: Ready to work with Modi govt for Bihar's development </p><p>RJD is the biggest partner in the Grand Alliance with 80 out of the cumulative 178 seats the grouping has won in the 243-member House. JD(U) has 71 MLAs and Congress 27.</p><p>Saying that the official date for the swearing-in ceremony for the new government would be announced only on November 14, Kumar, however, averred that the media was free to make guesses regarding the date and venue for the said event.</p><p>Media reports backed by some senior members of JD(U) have indicated November 20 as the "most likely date" for the oath- taking ceremony at Kumar's favourite venue, Gandhi Maidan.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish-story_180_111115041143.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish-story_305_111115041143.jpg
</highres><caption><![CDATA[ Nitish Kumar. PTI photo. ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/process-for-govt-formation-to-start-on-november-14-says-nitish-kumar/1/521360.html
]]></weburl></item><item><storyid>521238</storyid><headline><![CDATA[
PM Modi, Arvind Kejriwal may attend Nitish Kumar's oath taking
]]></headline><credit><![CDATA[ Giridhar Jha ]]></credit><date>2015-11-11T06:01:46+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Janata Dal-United stalwart Nitish Kumar will take oath as the chief minister for the fifth time in Bihar on November 20.
]]></kicker><body><![CDATA[
<p>Janata Dal-United stalwart Nitish Kumar will take oath as the chief minister for the fifth time in Bihar on November 20.</p><p>Nitish will head a coalition government consisting of JD-U, Rashtriya Janata Dal and the Congress after the Grand Alliance stormed to power with a massive majority in the state Assembly elections.</p><p>Also read: The way ahead for new Bihar and its challenges <br /></p><p>Grand Alliance sources said that the swearing-in ceremony would take place at the historic Gandhi Maidan and several dignitaries were expected to attend it. Prominent among those who are expected to attend the swearing-in ceremony are Congress president Sonia Gandhi, former prime ministers Manmohan Singh and H D Deve Gowda, West Bengal Chief Minister Mamata Banerjee and Delhi Chief Minister Arvind Kejriwal.</p><p>Also read: Over 50 per cent of new Bihar MLAs have criminal background, says study <br /></p><p>BJP veteran Lal Krishna Advani and Prime Minister Narendra Modi are also likely to be invited to the ceremony.</p><p>JD-U's Bihar president Vashishtha Narayan Singh said all the leaders who had extended supported to the grand alliance would be invited to the ceremony, besides others.</p><p>Party sources said that the swearing-in ceremony would be held after the Diwali and Chhath festivities.</p><p>Though there was no official confirmation about the shape and size of the ministry, the new council of ministers may have 36 members, including Chief Minister Nitish Kumar.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath---1_180_111115114527.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish-oath---1_305_111115114527.jpg
</highres><caption><![CDATA[ Nitish Kumar ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/pm-modi-arvind-kejriwal-may-attend-nitish-kumars-oath-taking/1/521238.html
]]></weburl></item><item><storyid>521232</storyid><headline><![CDATA[ BJP is the most secular party, says Rajnath Singh ]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-11T04:46:38+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
The Home Minister, who has offered a dialogue with dissenting artistes, on Tuesday said the party failed to read the social equations in Bihar.
]]></kicker><body><![CDATA[
<p>Rejecting the view that sectarian hatred is on the rise under the Narendra Modi-led NDA government, and that the intolerance debate triggered off BJP's poll debacle in Bihar, Home Minister Rajnath Singh said BJP is the most secular party in the country.</p><p>He also offered to have a dialogue with the dissenting writers, filmmakers and artistes, who have returned government awards for protesting against the rising intolerance in the country. "If there is one party that is secular, it is BJP," Singh said.</p><p>Singh has been the only one in the government who has not taken an aggressive stand against those returning awards while the BJP has in the past called it a manufactured protest. "I welcome those returning awards to have a dialogue. We are willing to hear them out as their suggestions are valuable and should be deliberated upon," Singh said while interacting with journalists on Tuesday.</p><p>Also read: Advani, other veterans speak up on Bihar loss, seek accountability <br /></p><p>Several BJP leaders have faced criticism for making communally charged statements recently.</p><p>Assessing the defeat faced by BJP in Bihar, the Home Minister said the party failed to read the social equations in the state and out rightly rejected suggestions that RSS chief Mohan Bhagwat's quota review remark had a negative impact on NDA's poll prospects in Bihar.</p><p>"Bhagwat's statement was not damaging. It was nothing controversial. We can't think like that. He had only said that reservation should continue," Singh said.</p><p>Bhagwat had said there is a need to have a fresh look as to who should get the benefit of quota, in comments that kicked up a political storm ahead of the Bihar polls. Singh also asserted that the PM cannot be held responsible for NDA's humiliating defeat.</p><p>PM Modi's popularity intact despite Bihar loss: Pakistani media <br /></p><p>"It's BJP's loss and not of the Prime Minister," he said. </p><p>Singh said the BJP will study and analyse all aspects of party's defeat in the polls and will take action accordingly. Victory and defeat are part of the democratic process.</p><p>"We had won elections in the past, we had lost elections in the past. We will not do justice to future if we decide future only on the basis of one elections, he added. The Home Minister was candid in admitting that the results had puzzled him as he had seen good public presence during 50 rallies addressed by him.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/rajnath-singh---23_180_111115105414.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/rajnath-singh---23_305_111115105414.jpg
</highres><caption><![CDATA[
Over 50 per cent of new Bihar MLAs have criminal background, says study.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bjp-is-the-most-secular-party-says-rajnath-singh/1/521232.html
]]></weburl></item><item><storyid>521231</storyid><headline><![CDATA[
Bihar defeat: Advani, Joshi and Sinha take on BJP leadership
]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-11T04:22:50+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
The statement was issued late Tuesday evening following a meeting at Murli Manohar Joshi's residence.
]]></kicker><body><![CDATA[
<p>Knives are out in the BJP and it is the Old Guard that has drawn first blood.</p><p>Scathing attack on the party's top leadership for the Bihar debacle has come from none other than party veterans L K Advani, Murli Manohar Joshi, Yashwant Sinha and others.</p><p>Two days after the crushing defeat in the crucial polls and a day before Diwali, the veterans on Tuesday lashed out at Team Modi.</p><p>"The results of the Bihar elections show that no lesson has been learnt from the fiasco in Delhi," said the opening line of the statement which bore the signature of party veteran and former Union finance minister Yashwant Sinha.</p><p>Also read: People saw a Lalu in PM, says Begusarai MP Bhola Singh <br /></p><p>The brief but strongly-worded statement was issued following a meeting at the residence of Murli Manohar Joshi on Tuesday evening. Party veterans L K Advani, Arun Shourie and K N Govindacharya were present in the meeting wherein they deliberated upon the current situation in the party apart from the loss the BJP faced in the Bihar polls.</p><p>This is first such attack on the leadership of PM Narendra Modi and party chief Amit Shah in which the stalwarts have also raised questions over the explanation of the party's senior leaders that no individual is responsible for the defeat in Bihar polls and the loss was because of wrong caste arithmetic. While pulling the senior leadership up for shrugging off responsibility, the veterans demanded that accountability for the loss should be fixed.</p><p>"To say that everyone is responsible for the defeat in Bihar is to ensure that no one is held responsible. It shows that those who would have appropriated credit if the party had won are bent on shrugging off responsibility for the disastrous showing in Bihar," said the statement.</p><p>Also read: Post victory, Nitish's poll strategist Prashant Kishor gets Mamata's invite <br /></p><p>The old guard also raised serious questions over the style of functioning in the party wherein power lies in a few hands. The veterans said that the way the party has been functioning since the past one year has weakened the organisation and that is the main reason behind the loss in Bihar polls. "The principal reason for the latest defeat is the way the party has been emasculated in the last year," said the statement.</p><p>Asking for review of the defeat, the veterans said that there should also be an analysis on how the party has been forced to kowtow to a handful. The veterans also warned that this style of functioning has destroyed the consensual character of the party.</p><p>"A thorough review must be done of the reasons for the defeat. As well as of the way the party is being forced to kowtow to a handful, and how its consensual character has been destroyed," said the statement.</p><p>In a veiled attack on PM Narendra Modi and BJP chief Amit Shah, the brief note issued by the veterans said that the review of the loss must not be done by those who managed and were responsible for the Bihar campaign.</p><p>Also read: BJP ran negative campaign in Bihar, says Badal Jr <br /></p><p>"This review must not be done by the very persons who have managed and who have been responsible for the campaign in Bihar," the note said.</p><p>The statement was planned at a short notice on Tuesday evening and it was issued at around 9 pm following the meeting at Joshi's house.</p><p>After the 2014 General Elections, the BJP leadership had dropped the veterans from the parliamentary board and formed a new committee 'Marg Darshak Mandal' to reinstate them.</p><p>The Bihar mandate - in which the NDA had won only 58 seats in the 243-member house - is being seen by many as a reflection of the 18-month performance of the Narendra Modi government.</p><p>BJP's response</p><p>Union Ministers Rajnath Singh, Venkaiah Naidu and Nitin Gadkari issued a statement, saying that "it would certainly welcome any guidance and suggestion of our seniors."</p><p>The statement said, "the party has been very fortunate to have been led by Shri Atal Bihari Vajpayee and Shri L.K. Advani for decades. They had set a healthy precedent of the party collectively taking up responsibility for victories and defeats."<br /></p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bihar-polls---3_180_111115105319.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bihar-polls---3_305_111115105319.jpg
</highres><caption><![CDATA[ L K Advani, Murli Manohar Joshi ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-defeat-lk-advani-mm-joshi-and-yashwant-sinha-take-on-bjp-leadership/1/521231.html
]]></weburl></item><item><storyid>521230</storyid><headline><![CDATA[
People saw a Lalu in PM, says Begusarai MP Bhola Singh
]]></headline><credit><![CDATA[ Giridhar Jha ]]></credit><date>2015-11-11T04:13:22+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
After facing humiliating defeat in the Bihar assembly elections, the BJP is under fire from its own senior party men over its poll campaign led by Modi.
]]></kicker><body><![CDATA[
<p>After facing humiliating defeat in the Bihar assembly elections, the BJP is under fire from its own senior party men over its poll campaign led by Prime Minister Narendra Modi.</p><p>A day after Patna Sahib MP Shatrughan Sinha questioned the party's wisdom to make excessive use of the prime minister in the state Assembly polls, BJP's Begusarai MP Bhola Singh took exception to the language used by Modi and party president Amit Shah at their rallies during the campaigning.</p><p>Also read: The way ahead for new Bihar and its challenges <br /></p><p>Accusing Modi of injecting communalism instead of talking about Bihar's development in his campaign, Singh said that Modi fell into the trap of RJD president Lalu Prasad by using inappropriate language.</p><p>"People went to Modi looking for a prime minister but they saw a Lalu in him," he said.</p><p>Singh said that Chief Minister Nitish Kumar, on the other hand, remained dignified attracting voters from different communities.</p><p>Also read: Advani, other veterans speak up on Bihar loss, seek accountability <br /></p><p>"The prime minister fell to Lalu's googly and left his 'Sabka saath sabka Vikas (Development for all)' slogan," he said. "He started speaking in Lalu's language. He began using undignified language while Nitish did not forget decorum even in the battlefield."</p><p>The veteran leader said that the focus of campaign by Modi and Shah should have been Bihar's underdevelopment and its progress. "Instead, the issues of cow and Pakistan were raised," he said.</p><p>The eight-term MLA said that RSS chief Mohan Bhagwat should not have a political comment on reservation during a crucial election.</p><p>Singh found ample support from Shatrughan Sinha. "Bhola Babu is a learned man whose views carry weight. We all respect him," he said.</p><p>Shotgun also hit back at party leader Kailash Vijayvargiya who had used a dog analogy to criticise him over his meeting with Nitish and Lalu in Patna on Monday. "People want my reaction to Vijayvargiya's remark.</p><p>My reaction to small or big flies in any party is "Haathi chale Bihar,....bhaunken hazaar," he tweeted on Tuesday.<br /></p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bhola-singh_180_111115104951.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bhola-singh_305_111115104951.jpg
</highres><caption><![CDATA[ BJP's Begusarai MP Bhola Singh. ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/people-saw-a-lalu-in-pm-says-begusarai-mp-bhola-singh/1/521230.html
]]></weburl></item><item><storyid>521097</storyid><headline><![CDATA[ The way ahead for new Bihar and its challenges ]]></headline><credit><![CDATA[ Pankaj Kumar Jha ]]></credit><date>2015-11-10T21:07:55+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
The mandate Nitish Kumar has got is a reflection of his coalition's reach across votebanks and aspirations.
]]></kicker><body><![CDATA[
<p>With Nitish Kumar being re-elected Bihar chief minister, it is significant to minutely examine the new phase of good governance here. My book Sushasan ke Aaine mein Naya Bihar (Reflections from a well-governed Bihar) had been just published some 5 years ago. Around that time, Nitish Kumar had sai
]]><![CDATA[
d Bihar was an "eatable" that was always falling prey to insects.&nbsp; In such a scenario, do the people give up eating it? And live hungry? No, said Nitish. He said, "You just wipe the insects away with one hand and eat it with the other hand." On the basis of that analogy, obstacles in the way of development can be eradicated. It is clear that on the basis of such intention and commitment only Nitish Kumar was able to take some revolutionary decisions. The Janata darbar and later the Chief Minister at the Janata's darbar, Information Call Centre, the formation of Mahadalit Commission, revamping of Nalanda University, 50 per cent reservation for women in panchayat institutions, cycles and uniforms for schoolgirls, Bihar Special Court Act, the formation of SAP, the strengthening of law and order by the formation of fast track courts are few important examples. The other fact is that Nitish Kumar had governed for a decade too.</p><p>But, this time the 'win' has its own dimensions. Then Nitish Kumar was leading the NDA in Bihar. This time he had contested the election by forming an alliance with Lalu Prasad's RJD and the Congress as the Mahagathbandhan and won spectacularly. That's why the results this time have to be seen and analysed not only from Nitish Kumar's point of view but rather by the Lalu and Congress factors too. This new phase of governance has three significant participants.</p><p>a.) Nitish Kumar was not only the face of development but also social justice. We saw that everybody was convinced with Nitish Kumar's flawless image. People from the remotest areas of Seemanchal and from the flood-affected areas of the Kosi had maintained that the schemes of Nitish Kumar's government like cycle and uniforms distribution has worked and had influenced ground reality. In the same way, women teachers said clearly that they have not seen the Gujrat Model but had clearly seen the works of Nitish Kumar. They all were scared that they would not get the benefits and jobs if Nitish Kumar would not be able to form the government. This way we saw that half the population supported Nitish Kumar. Important fact is that the way Nitish Kumar had brought schemes for Dalit bastis. These had strengthened the image of social justice of Nitish Kumar.</p><p>b.) Where at one end Nitish Kumar's face was influencing Bihar voters, at the other end was Lalu's base, the Muslim-Yadav equation. Starting from day one, Lalu was attracting Yadavs by saying we will bring Mandalraaj and playing on Muslim fears of the BJP. While Nitish was seeking votes by showcasing his work, Lalu was attacking Prime Minister Narendra Modi and BJP chief Amit Shah. This is the reason that despite the "jungle raaj" tag, Lalu's party is at the top of this alliance. Today tea vendor Mangal Yadav must be happy on seeing the win of his Sarkar (Lalu Prasad). He must be welcoming everyone to have tea at his cost.</p><p>c.) Third factor is related to the Congress. This election came as a fresh breath for the Congress which had ruled Bihar in the 1980s. This should not be seen just in relation to seats only. Throughout the whole journey, ranging from the ST reserved seat of Manihari to Muslim populated areas of Kishanganj to Bhagalpur to Samastipur, we saw that old Congress supporters (Brahmins and Muslims) found a new enthusiasm for the party. One of the Congress supporters, Amina Khatun of Saudagar Patti, Kishanganj said, "I am an old Congress supporter and have been with Congress since when it had the cow and calf symbol. As long as I live, I will vote for the Congress only." This is the base on the basis of which Congress had governed Bihar and is overall good news for the party's supporters. And for its leaders in Delhi.</p><p>There are challenges too:</p><p>1. Bihar suffers from flood and drought.&nbsp; North Bihar's 76 per cent population is hit by floods. In 2014, the state disaster management department declared 33 of the state's 38 districts drought hit. Floods and drought can destroy governance and progress in Bihar.</p><p>2. Infrastructure development is a big issue for the Nitish government. During my Bihar visit, I found that everyone needs more Bijli, Sadak and Pani&nbsp; along with toilets and good health.</p><p>3. Bihar's jute, flour and sugar industries have been closed for a long. Can we think of a way out for re-industrialising the state?</p><p>4. Unemployment is a challenge with widespread unemployment among youth. A decade ago, migrants were mainly from poor households but today migration is among youngsters from all sections of society.</p><p>5. Education is also a big challenge for good governance. The level of primary education is deteriorating considerably. In higher education, the scarcity of teachers in colleges, delays in academic sessions, poor level of research have become challenges.</p><p>6. Coordination within allies will be problematic for the new government. It would be a challenge for Lalu Prasad and Nitish Kumar to work together.<br /></p><p>7. Cooperation with the Centre will be also a big challenge for the Nitish government. During Bihar election, the package war between Centre and state came out into the open at a Modi rally.</p><p>(Pankaj Kumar Jha holds a doctorate from the Department of Political Science, Delhi University. He is travelling through Bihar under the Project EECURI&nbsp; led by the London School of Economics &amp; Political Science.)</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitishlalu-story_180_111015091733.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitishlalu-story_305_111015091733.jpg
</highres><caption><![CDATA[ Nitish Kumar with Lalu Prasad. PTI photo. ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/the-way-ahead-for-new-bihar-and-its-challenges/1/521097.html
]]></weburl></item><item><storyid>520671</storyid><headline><![CDATA[
Post victory, Nitish's poll strategist Prashant Kishor gets Mamata's invite
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-10T13:49:11+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Prashant Kishor had quit a UN health experts job in 
 Africa in 2011 and returned to India to form a group of young 
 professionals who devised the strategy to project Modi as the face of 
 good governance in 2012 Gujarat polls and last years general 
 elections.
]]></kicker><body><![CDATA[
<p>After storyboarding massive electoral wins for Narendra Modi and Nitish Kumar in 2014 and 2015 respectively, 'master strategist' Prashant Kishor may be seen charting out poll campaign ideas for West Bengal Chief Minister Mamata Banerjee. Assembly election in West Bengal is due in 2016.</p><p>According to reports, Mamata's office has approached Kishor to manage Trinamool Congress's poll campaign. However, the CM is tighlipped about the idea of roping in Kishore.</p><p>Also read- Meet Modi's ex-poll strategist who helped Nitish win <br /></p><p>"There hasn't been any discussion with him as of now.... How can I tell you?" The Telegraph d Mamata, as saying.</p><p>"The Mamata Banerjee camp has evinced interest in seeking the services of our organisation for the 2016 Bengal Assembly polls," one of the directors of the Indian Political Action Committee (I-PAC), the cross-party advocacy group led by Kishor, said in reply while replying to a question.</p><p>When asked about the development, Trinamool spokesperson Derek O'Brien also refused to divulge much details. "At this juncture, it is too premature to comment on the matter. For now, let us just celebrate the resounding defeat of intolerance in Bihar," O'Brien told the newspaper.</p><p>Prashant Kishor, a native of Bihar, had quit a UN health experts job in Africa in 2011 and returned to India to form a group of young professionals who devised the strategy to project Modi as the face of good governance in the 2012 Gujarat polls and last years general elections with resounding success.</p><p>Also read- Meet Prashant Kishor, the man who scripted Modi's rise and fall <br /></p><p>Kishor, the man with the Midas touch, replicated the feat once again when Nitish Kumar secured a third consecutive term trouncing BJP-led NDA in Bihar where Modi, an arch rival of the JD(U) leader, had staked it all, having addressed at least 31 election rallies, unusual for a Prime Minister in a state poll. </p><p>Kishor, 37, who conceptualised and implemented Modi's popular chai pe charcha initiative, substituted it with parcha pe charcha (discussion over pamphlets) under which Nitish's poll managers sought feedback from people on the state governments performance over the past decade.</p><p>Realising that the JD(U) cannot match the resources of BJP, Kishor's team also devised the Har Ghar Dastak (knock on every door) that helped the party establish a personal connect with the masses.</p><p>When top BJP leaders were busy criss-crossing Bihar on helicopters, Nitish Kumar and workers of his party went knocking the doors of the electorate seeking their vote as part of the direct outreach initiative.</p><p>When asked why he switched over to Modi's rival, Kishor said," Nitish Kumar is one of the country's most credible politicians."</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/poll-strategy-1_180_110915083342_111015015210.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/poll-strategy-1_305_110915083342_111015015210.jpg
</highres><caption><![CDATA[
Bihar CM Nitish Kumar with 37-year old Prashant Kishor, who was Modi's strategist for the 2014 Lok Sabha polls.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/post-victory-nitishs-poll-strategist-prashant-kishor-gets-mamatas-invite/1/520671.html
]]></weburl></item><item><storyid>520575</storyid><headline><![CDATA[
It's not a defeat, party committed suicide in Bihar, says BJP MP
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-10T11:12:14+05:30</date><city><![CDATA[ Patna/New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
Party MP from Begusarai, Bhola Singh, on Tuesday held Prime Minister 
 Narendra Modi and other top party leaders responsible for the poll 
 debacle.
]]></kicker><body><![CDATA[
<p>Voices of dissent continue to flow in the Bharatiya Janata Party (BJP) following Bihar Assembly election results . Party MP from Begusarai, Bhola Singh, on Tuesday held Prime Minister Narendra Modi and other top party leaders responsible for the poll debacle. Read: 10 lessons that Modi's BJP ought to learn from crushing Bihar defeat <br /></p><p>Talking to the media, Singh termed BJP's defeat as suicide. "It is not a defeat of the BJP, it is a suicide by the party itself. The language which the PM and other leaders used during campaigning was least required. Cow (beef), Pakistan issues were unecessarily raised by our leaders during election campaigning," Singh said. </p><p>The BJP-led NDA could only manage to win 58 seats, while the JD(U), RJD, Congress combine bagged 178 seat in the 243-seat Bihar Assembly. The BJP has admitted that it failed to read the popularity surge of Grand Alliance , but political analysts believe that statements from PM Modi, party chief Amit Shah and RSS chief Mohan Bhagwat made during the polls played a major role in the rout.</p><block class="twitter-tweet" lang="en"><p>Rozi roti aur acchi zindagi dene ke badle logon ne gaaye aur Pakistan ko chunaav ka mudda banaya: BJP MP Bhola Singh pic.twitter.com/uwYMVNiRz8</p> ANI (@ANI_news) November 10, 2015</block><script src="//platform.twitter.com/widgets.js" async="" charset="utf-8"></script><p>Addressing the media after BJP Parliamentary Board meeting on Monday, Union Finance Minister Arun Jaitley said, "I feel that our partners have tried their level best. We failed to estimate the popularity surge of Grand Alliance. Their transferability of votes was better than us and so size of that coalition arithmetically became more than us... the biggest reason for their win."</p><p>Though he refrained from naming any of the party's leaders, Jaitley admitted that statements by saffron hotheads hurt the party's campaign in Bihar by deflecting from the main theme of development.</p><p>"Some irresponsible statements did change the narrative. Such things are not expected from responsible politicians. I had repeatedly intervened in order to make sure that the narrative goes as per our original plan," Jaitley told TV channels after Monday's crucial meeting.</p><p>Jaitley, however, defended the decision to make Prime Minister Narendra Modi the face of the Bihar campaign. "The main reason for the poll defeat was that the NDA's social arithmetic did not add up. Responsibility for loss and victory was collective," he said.</p><p>Statements from ministers of state VK Singh, Mahesh Sharma, Giriraj Singh Sanjeev Balyan and leaders like Yogi Adityanath, Sakshi Maharaj and Kailash Vijayvargiya over issues ranging from Dadri, Shah Rukh Khan to the arson attack on a Faridabad Dalit family damaged BJP's Bihar plans hugely. <br /></p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/bhola-singh_180_111015112041.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/bhola-singh_305_111015112041.jpg
</highres><caption><![CDATA[ Bhola Singh ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/its-not-a-defeat-party-committed-suicide-in-bihar-says-bjp-mp/1/520575.html
]]></weburl></item><item><storyid>520554</storyid><headline><![CDATA[
Bihar govt formula out, Nitish to take oath on November 20
]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-10T10:32:41+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
After the Grand Alliance's landslide victory in the Bihar Assembly 
 polls, Nitish Kumar is likely to take oath as Chief Minister of the 
 state on November 20.
]]></kicker><body><![CDATA[
<p>After the Grand Alliance's landslide victory in the Bihar Assembly polls, Nitish Kumar is likely to take oath as Chief Minister of the state on November 20. The oath taking ceremony will take place at the Gandhi Maidan.</p><p>Also Read | Shatrughan Sinha meets Nitish, BJP leaders call for action <br /></p><p>According to reports, meeting of newly elected legislators of the Grand Alliance will be convened in Patna in which leader of the grand alliance will be elected.</p><p>As per the constitutional norms, 36 ministers, including the chief minister, could be included in the new cabinet.</p><p>Watch: Bade, Chhote miyan shake a leg after Bihar victory </p><p>So Nitish Kumar will be sworn in as the chief minister of Bihar for the fifth time after the Chhath festival to be celebrated in the third week of November. Chhath is the most popular festival in Bihar.</p><p>As per the reports accessed by India Today, there will be 16 ministers from Lalu Prasad's Rashtriya Janata Dal, 15 from the JD-U and 5 from the Congress. Sources say Nitish Kumar is likely to apply the tested formula of one minister for every five lawmakers. Rashtriya Janata Dal(RJD) chief Lalu Prasad Yadav's sons Tej Pratap and Tejaswi who won respectively from Mahua and Raghopur are likely to get important portfolios in Nitish's cabinet. After winning the election, both of them said they are ready to be ministers in Nitish Kumar's government. </p><p>Meanwhile couple of RJD members have expressed their desire to become ministers in Bihar government.&nbsp; <br /></p><p>Also Read | Nitish Kumar to take oath after Chhath festival <br /></p><p>The RJD emerged as the single largest party with 80 assembly seats, followed by the JD-U with 71 and the Congress with 27.</p><p>The Mahagathbandhan won 178 seats in Bihar, a commanding two-third majority in the 243-member assembly. The Bharatiya Janata Party and its allies had to settle for a mere 58 seats.</p><p>Also Read | Post-Bihar verdict, BJP goes into huddle <br /></p><p>The victory of the Grand Alliance brought both the RJD and the Congress back on the centre-stage of Bihar politics with a bang. The victory left Lalu, whose party had won only 22 seats in the 2010 assembly elections, ecstatic. </p><p>The victory also gave a fresh lease of life to the Congress which had been struggling to regain its toehold in the state for several years. The party came up with its best performance in an assembly election in 20 years by winning 27 out of 41 seats. <br /></p><p>Earlier, Union Finance Minister Arun Jaitley said that the Bharatiya Janata Party (BJP) respects the mandate given to the Grand Alliance by the people of Bihar and hopes that they will work for the development of the state.</p><p>Addressing the media after BJP's Parliamentary Board meeting in New Delhi on Monday, Arun Jaitley said, "I feel that our partners have tried their level best. We failed to estimate the popularity surge of Grand Alliance. Their transferability of votes was better than us and so size of that coalition arithmetically became more than us... the biggest reason for their win."</p><p>BJP president Amit Shah called upon RSS chief Mohan Bhagwat after several party MPs said the saffron party chances at the Bihar hustings were unfairly impacted by the latter's interjection on caste-based quota. </p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/nitish-kumar_story_180_111015103241.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/nitish-kumar_story_305_111015103241.jpg
</highres><caption><![CDATA[
Bihar Chief Minister Nitish Kumar (Photo: Sonu Kishan)
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-govt-formula-out-nitish-to-take-oath-on-november-20/1/520554.html
]]></weburl></item><item><storyid>520515</storyid><headline><![CDATA[
Bihar election verdict too big to ignore delivery: Shivanand Tiwari
]]></headline><credit><![CDATA[ Darpan Singh ]]></credit><date>2015-11-10T04:05:55+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Tiwari, who held key positions in their respective governments in Bihar,
 said it was in Lalu's own interest to let Nitish run Bihar effectively.
]]></kicker><body><![CDATA[
<p>Shivanand Tiwari, who has known Nitish Kumar and Lalu Yadav for decades, has said it would be a challenge for the 'two strong personalities' to work together, but exuded confidence that 'they would manage just fine'.</p><p>Tiwari, who held key positions in their respective governments in Bihar, said it was in Lalu's own interest to let Nitish run Bihar effectively. "I met Lalu after the verdict. He was very clear. The mandate is too big to ignore delivery," Tiwari said.</p><p>"Both are two different individuals. Differences are only natural. But it is in their interest to sort them out to ensure the new government functions smoothly," he said. Amid a raging national debate on religious intolerance, NDA on Sunday suffered a crushing defeat to a coalition of these two-who joined hands after a decade of bitter rivalry-and Congress.</p><p>The critics of the Grand Alliance say Lalu is in a hurry to pass on his mantle to sons, and-given his alleged track record of caste-driven governance-would not let Nitish continue with his development agenda.</p><p>"Lalu knows it better than anybody else that the longevity of the mantle he wants to pass on depends on the performance of this government. It has to do well, enough to earn a second mandate. It is in Lalu's interest that a government in which his sons are involved does well," Tiwari, in his early 70s, said.</p><p>RJD being the single-largest party in this election, Lalu may want a say in the administration. Nitish will have to offer key portfolios to RJD. The socialist leader, who has been on a break from active politics since 2014, says Lalu has changed. "Portfolio allocation is a routine affair. He is not what he was 10 years ago," he said.</p><p>Nitish and Lalu are both products of the JP movement of the 1970s. When Janata Dal won Bihar in 1990 and Lalu became CM, Nitish was by his side. Nitish parted ways over Lalu's alleged preference to Yadavs in government schemes, and formed a separate outfit in 1994. He ended the 15-year rule of Lalu-Rabri by leading the NDA to victory in 2005. Lalu has now returned to Bihar's centrestage from political wilderness.</p><p>"I'm not saying everything was fine in Lalu's rule. But post-Mandal, Bihar faced a social churning, and upheaval-often branded as jungle raj. See how, despite the corruption taint, Lalu has emerged as a real hero in this election," Tiwari said.</p><p>Nitish grew at the expense of Lalu but left NDA in 2013 when Modi became its prime ministerial candidate. After NDA swept the 2014 Lok Sabha polls, decimating both JD-U and RJD, a helpless Nitish joined forces with Lalu after a gap of two decades. Tiwari was a minister in an RJD government, before joining Nitish's JD-U who made him a Rajya Sabha MP. Lalu declined when Tiwari wanted to return to RJD after being expelled by JDU in 2014 for speaking against Nitish. Tiwari, who now often meets Lalu during morning walks, was a key spokesperson in both governments.</p><p>In June this year, Lalu said 'he was drinking poison' to accept the leadership of Nitish for the Bihar elections. Nitish was the main force behind Lalu's going to jail over corruption charges.</p><p>When in power with BJP, Nitish never allowed a second power centre. With Lalu-a strong CM in the past and the senior partner now-this may not be easy. Also, Kumar likes to go by the rulebook, while Lalu has been more of a maverick.</p><p>Tiwari however says Nitish and Lalu are politically in sync. "These two do bring with themselves a set of contradictions. They are distinct personalities. But I don't see any ideological differences. The differences they have are of temperament, working style. For example, Lalu has not been very disciplined," he said.</p><p>Tiwari also defended the caste spin that the Grand Alliance gave to the Bihar campaign to stall Modi's dream run. "It was a social coalition that weighed heavily in their favour. Caste is the hinge of Bihar politics. Can one deny this?"</p><p>Nitish has returned to power for a third time in Bihar, but this time he has also emerged as a potential nucleus around which an anti-Modi coalition may take shape ahead of the 2019 Lok Sabha elections. Earlier this year the BJP suffered a drubbing at the hands of Aam Aadmi Party in Delhi.</p><p>In both elections, Modi campaigned fiercely. But soon after the Bihar verdict was out, Lalu indicated he would assume a more national role, leaving Bihar to Nitish?</p><p>"I wouldn't like to read too much into these statements. Just look at the cohesion the two formidable local leaders showed during campaigning. They needed each other to win. They still need each other for Bihar's sake," Tiwari said.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/tiwari-cartoon-1_180_111015085530.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/tiwari-cartoon-1_305_111015085530.jpg
</highres><caption><![CDATA[
Shivanand Tiwari has held key positions in governments run by both the leaders.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-verdict-too-big-to-ignore-delivery-shivanand-tiwari/1/520515.html
]]></weburl></item><item><storyid>520514</storyid><headline><![CDATA[
Shatrughan Sinha meets Nitish, BJP leaders call for action
]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-10T03:44:15+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
BJP leaders continue to demand action against party MP Shatrughan Sinha for holding the party responsible for the Bihar election debacle.
]]></kicker><body><![CDATA[
<p>Clamour for action against BJP MP and veteran actor Shatrughan Sinha gathered momentum on Monday after the Patna Sahib MP fired fresh salvos against the party leadership while holding them responsible for the Bihar drubbing . The party indicated that action was imminent against the actor.</p><p>Sinha, who embarrassed the party during the Bihar campaign, invited angry barbs from party leaders with controversial BJP general secretary Kailash Vijayvargiya even comparing the actor with a dog, who runs after a car believing the vehicle is moving because of him.</p><p>"This party is not dependable on one person, it is a whole organisation and there is a big hierarchy here," said Vijayvargiya using the dog analogy to describe Shatrughan Sinha's conduct .</p><p>He went on to claim that Sinha's identity in politics is because of the BJP and he alone should decide on his loyalty to the party. "Shatrughan Sinha's identity in politics is because of the BJP and the party's identity is not because of him. How loyal he should be towards the party should be decided by him. Causing loss to the party even when you've taken so much from the party is for him to decide. I disagree with his behaviour," he said.</p><p>The Bollywood veteran said that Nitish Kumar was a successful, tried and tested chief minister who was the most respectable after former West Bengal chief minister Jyoti Basu.</p><p>Shotgun, as Shatrughan is popularly known, said that his meeting with Nitish was a courtesy call and it should not be misconstrued as his defiance of the party. "Even Prime minister Narendra Modi, Union Home minister Rajnath Singh and other senior leaders in the party have congratulated him on his victory," he said.</p><p>The actor- politician continued to provoke the BJP as he met Nitish Kumar to congratulate him on the Grand Alliance's victory. "There should be action against those responsible (for the loss).</p><p>They should be taken to task. As former home secretary and party leader RK Singh has said, responsibility should be fixed and those responsible for this loss should draw lessons even if action is not taken," he told reporters after meeting Kumar.</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/shotgun-11_180_111015083934.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/shotgun-11_305_111015083934.jpg
</highres><caption><![CDATA[
BJP MP Shatrughan Sinha greets Bihar CM Nitish Kumar in Patna on Monday.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bjp-leaders-call-for-action-on-shotgun/1/520514.html
]]></weburl></item><item><storyid>520473</storyid><headline><![CDATA[ Does Bihar verdict prove India is secular? ]]></headline><credit><![CDATA[ IndiaToday.in ]]></credit><date>2015-11-09T23:06:31+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ ]]></courtesy><kicker><![CDATA[
"The caste politics, and all other factors people are talking about, 
 were all add-ons on the basic issue that the very character of India 
 cannot be tinkered with or disrupted. This faith of one of the ancient 
 habitations of the world - the Indo-Gangetic plain - has reasserted 
 itself," said Yechury.
]]></kicker><body><![CDATA[
<p>The Grand Alliance made history in Bihar Assembly elections by scoring a landslide win over the BJP-led NDA. So, what was the message that the incredible election results from Bihar had sent right across India, asked Karan Thapar on his show To The Point on Monday.</p><p>The three questions he posed:<br /></p><ul><li>Does Bihar prove India is secular because it's 80 per cent Hindu majority is secular and will not allow itself to be divided by beef, religion or innuendos about Pakistan?</li><li>Has Bihar proved correct a slogan from Rajiv Gandhi's time that we would once mimic and deride - 'Mera Bharat Mahaan'?</li><li>Where does the outcome leave Prime Minister Modi and BJP President Amit Shah? Are they damaged or is that an exaggerated conclusion?</li></ul><br />CPM General Secretary and Rajya Sabha member Sitaram Yechury, former Congress minister and MP Mani Shankar Aiyar, JD(U) Rajya Sabha MP Pavan Varma, BJP national spokesperson Nalin Kohli and well-known columnist Ashok Malik.<p> funfactsThe six big questions <ol><li>What message have the Bihar Assembly polls and its historic results sent out?</li><li>Where does the Bihar verdict leave Amit Shah?</li><li>Is it the defeat of divisive politics?</li><li>Was the Bihar polls caste-driven?</li><li>Will the prime minister accept the blame for Bihar debacle?</li><li>Is the victory in Bihar a boost to Rahul Gandhi's political stand?</li></ol>funfacts <p>"The caste politics, and all other factors people are talking about, were all add-ons on the basic issue that the very character of India cannot be tinkered with or disrupted. This faith of one of the ancient habitations of the world - the Indo-Gangetic plain - has reasserted itself," said Yechury.<br />&nbsp;<br />"I accept the conclusion that Bihar and its people resisted the attempt to polarise the elections, and that was a very persisted attempt made by the BJP, especially in the last three phases of the election. But I would not yet come to the conclusion that all attempts to polarise fail. Hinduism, left to itself, is one of the most eclectic and tolerant religions, a way of life. To try and kill it is to try killing a fly with a sword. The real danger is the attempt to polarise it, and fortunately the people of Bihar this time resisted the attempt to polarise it," said Varma.<br />&nbsp;<br />"Polarisation is a reality in terms of it could be either side. Certainly there were comments that were ill tempered, by some leaders. But to say that was the main script and the electorate has vastly rejected or voted only on that issue will be a tad hasty. We should wait for the final election analysis and we'll find out what is the story. BJP after all did poll the highest numbers of votes for a single largest party - 24 per cent, almost 6 percent ahead of the others.&nbsp; What we did not expect was the votes on the other side would come together so effectively, because in the past elections have showed that it is also about chemistry, and not just arithmetic. Here arithmetic seems to have worked conclusively," said the BJP spokesperson Kohli.<br />&nbsp;<br />"Mera bharat mahaan hi hai [My India is certainly great]. It is clear from the results in Bihar that the insidious attempt at hijacking the idea of India, which is embedded in our constitutional values, has been halted in mid-heist. India has returned to the route on which it was moving ever since the struggle for independence sought to bring all Indians together. Much of the credit of this should go to the 80 percent of our population that considers itself to be Hindu. But, I do not think that secular spirit is limited to the Hindus. The Muslims and other minorities of India are also secular. This country is secular because Indians are secular. There is nothing particularly exclusive about secularism," said Aiyar.</p><p>Watch full debate here:</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/karan_180_110915112442.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/karan_305_110915112442.jpg
</highres><caption><![CDATA[ ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/does-bihar-verdict-prove-india-is-secular/1/520473.html
]]></weburl></item><item><storyid>519708</storyid><headline><![CDATA[ Bahubali legislator Anant Singh makes it from jail ]]></headline><credit><![CDATA[ Giridhar Jha ]]></credit><date>2015-11-09T04:00:02+05:30</date><city><![CDATA[ Patna ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Bahubali (strongman) legislator Anant Singh had no problem in retaining his Mokama seat even though he had been lodged in jail for several months due to his alleged involvement in an abduction-cum-murder-case.
]]></kicker><body><![CDATA[
<p>Bahubali (strongman) legislator Anant Singh had no problem in retaining his Mokama seat even though he had been lodged in jail for several months due to his alleged involvement in an abduction-cum-murder-case.</p><p>Anant who had won the 2005 ad 2010 Assembly polls on the JD-U ticket had quit the party after he was put behind bars.</p><p>Chhote Sarkar, as Anant is known in the region, did not even campaign for a single day but he defeated JD-U spokesman Neeraj Kumar from his stronghold.</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/sonrise-lalu-bahubali-10_180_110915085419.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/sonrise-lalu-bahubali-10_305_110915085419.jpg
</highres><caption><![CDATA[ Anant Singh ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bahubali-legislator-anant-singh-makes-it-from-jail/1/519708.html
]]></weburl></item><item><storyid>519707</storyid><headline><![CDATA[ RJD chief Lalu Prasad gives up his jinxed chair ]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-09T03:57:27+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Lalu Prasad refrained from sitting on a 'jinxed' chair while watching Assembly poll results on Sunday.
]]></kicker><body><![CDATA[
<p>RJD President Lalu Prasad has no qualms in wearing his superstitions on his sleeve. His recurring defeat in elections over the past ten years seems to have made him wary of a chair.</p><p>He refrained from sitting on a 'jinxed' chair while watching Assembly poll results on Sunday. "I did not sit on that chair because I had lost all polls in the past whenever I sat on that chair," Lalu said. "This time, I preferred to walk to and fro during the result announcements on TV instead."</p><p>He congratulated the media persons who stood guard outside his bungalow since 4 am. "I saw a herd of reporters with their cameras. I greeted them and asked them to let me walk on the lawns. They deserve congratulations for hard work."</p><p>&nbsp;</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/lalu-story_180_102615111605_110515103155_110915083849.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/lalu-story_305_102615111605_110515103155_110915083849.jpg
</highres><caption><![CDATA[ Lalu Prasad ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/rjd-chief-lalu-prasad-gives-up-his-jinxed-chair/1/519707.html
]]></weburl></item><item><storyid>519706</storyid><headline><![CDATA[ Sonrise for Lalu, sonset for others ]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-09T03:54:02+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Lalu Prasad's sons, Tej Pratap Yadav and Tejashwi Prasad Yadav may have registered convincing wins in their electoral debut but the kids of others did not have similar luck.
]]></kicker><body><![CDATA[
<p>Rashtriya Janata Dal president Lalu Prasad's sons, Tej Pratap Yadav and Tejashwi Prasad Yadav may have registered convincing wins in their electoral debut but the kids of others did not have similar luck.</p><p>Former CM Jitan Ram Manjhi's son Santosh Kumar Suman, who also made his debut, lost the Hindustani Awam Morcha (Secular) ticket from Kutumba (reserved) seat.</p><p>Arijit Shahswat, son of BJP MP Ashwini Kumar Choubey lost from Bhagalpur constituency. Another BJP candidate Nitish Mishra, former minister and son of former CM Dr Jagannath Mishra, also faced defeat from Jhanjharpur seat. Vivek Thakur, son of BJP leader Dr C P Thakur lost in Brahmapur constituency, while LJP MP Ram Chandra Paswan's son Prince Raj bit the dust from Kalyanpur seat.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/sonrise-lalu-bahubali-9_180_110915084912.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/sonrise-lalu-bahubali-9_305_110915084912.jpg
</highres><caption><![CDATA[ Tejashwi Yadav ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/sonrise-for-lalu-sonset-for-others/1/519706.html
]]></weburl></item><item><storyid>519705</storyid><headline><![CDATA[ Is another Front shaping up? ]]></headline><credit><![CDATA[ Siddhartha Rai ]]></credit><date>2015-11-09T03:48:36+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
What could not happen before the Bihar elections seems possible as its aftermath: the creation of a non-BJP front.
]]></kicker><body><![CDATA[
<p>What could not happen before the Bihar elections seems possible as its aftermath: the creation of a non-BJP front. While leaders of non-BJP parties, essentially those ruling the states and having strong regional appeal, had dabbled with the idea of joining forces with Nitish Kumar-Lalu Prasad-Congress 'Mahagathbandhan' before Bihar polls.</p><p>Buoyed at the massive victory of the Grand Alliance and conversely elated at the second and more consequential drubbing of the Narendra Modi juggernaut in Bihar after Delhi polls, both the leaders seemed looking at playing a larger role now. They expressed that Bihar election results had "national implications". The clarion call has all the possibilities to forge an alternative formed by regional satraps against the BJP.</p><p>Nitish, set to become the chief minister for the third consecutive term, suggested coming together of non-BJP forces at the Centre to provide a strong opposition. "The results have made it clear that people wanted a strong alternative at the national level and have rejected attempts at polarising the society. Bihar results reflect the mood of the nation. It is a milestone election despite an aggressive campaign by the BJP-led NDA and its attempts at polarising the electorate," he said. Kumar also asserted that it was now imperative that they work together to provide a strong alternative.</p><p>Kumar might be looking to become the prime ministerial candidate of such a political pole in the 2019 Lok Sabha polls, something he bitterly failed at in 2014. A weak Congress and the badge of having proved conclusively that PM Modi was not invincible could well become Kumar's big ticket.</p><p>Earlier, before Bihar went to the ballot confabulations had remained hot between West Bengal chief minister Mamata Banerjee, AAP supremo and Delhi chief minister Arvind Kejriwal, NCP leadership, SP patriarch Mulayam Singh Yadav of UP and the JD (U) to cobble together what Banerjee had called a non-BJP and non-Left "federal front".</p><p>Some tension could be read between what Lalu said in this context and Nitish's statements. Lalu suggested that while Nitish would handle the state as chief minister, he would embark on a national tour to raise awareness for an alternative to the "communal" BJP.</p><p><br /></p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/front-1_180_110915090001.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/front-1_305_110915090001.jpg
</highres><caption><![CDATA[
Delhi CM Arvind Kejriwal, West Bengal CM Mamata Banerjee, SP chief Mulayam Singh Yadav and the JD (U) had held discussions to form a non-BJP and non-Left 'federal front' before the Bihar Assembly elections.
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/is-another-front-shaping-up/1/519705.html
]]></weburl></item><item><storyid>519704</storyid><headline><![CDATA[
Modi, Shah, Jaitley responsible for Bihar debacle: Arun Shourie
]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-09T03:43:24+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Arun Shourie has held Narendra Modi, Amit Shah and Arun Jaitley responsible for BJP's defeat in the Bihar polls.
]]></kicker><body><![CDATA[
<p>Following his recent comment on the PM, former union minister Arun Shourie on Sunday again said that Prime Minister Narendra Modi, party president Amit Shah and Union minister Arun Jaitley should be held accountable for BJP's loss in Bihar elections and predicted that the silent non-cooperation movement in the party against the leadership will now deepen.</p><p>Also read: Bihar results: List of prominent winners, losers <br /></p><p>He said a Modi-centric campaign lacked credibility because of the unkept promises of the past and blamed BJP's divisive tactics for the drubbing.</p><p>Shourie, a minister in the Vajpayee government, who is no longer with the party, accused Shah and Jaitley of fomenting a coalition against Modi by forcing the other opposition parties, which commanding over 69 per cent of vote, to get into an alliance.</p><p>Also read: Arun Shourie: PM Modi's silence deliberate <br /></p><p>He said that the BJP came to power at the height of Modi's popularity with merely 31 per cent votes. "It is Modi, the master strategist (Shah) and Jaitley," he said when asked who should be held responsible for the defeat. "There is no fourth person in the party or the government."</p><p>He said a Modi-centric campaign, a divisive campaign and the campaign lacked credibility as promises of the past have not been kept. In this context, he referred to Modi's claim during Lok Sabha poll campaign that everybody will get Rs 15 lakh with the amount of black money he would bring to India if he was voted to power. And then their party president said it was a 'jumla', so people will obviously not take you seriously when you make new promises, he added.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/arun-shourie_180_110915083740.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/arun-shourie_305_110915083740.jpg
</highres><caption><![CDATA[ Former union minister Arun Shourie ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/modi-shah-jaitley-responsible-for-bihar-debacle-arun-shourie/1/519704.html
]]></weburl></item><item><storyid>519703</storyid><headline><![CDATA[ Bihar election exit polls get it all wrong ]]></headline><credit><![CDATA[ Mail Today Bureau ]]></credit><date>2015-11-09T03:36:03+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
Many exit polls went way off the mark as they gave a clear majority to the NDA.
]]></kicker><body><![CDATA[
<p>While Bihar might have made history of some sort in its election results, closely watched exit polls added another leaf to their own history by making another unreliable prediction. While those who predicted a close contest missed the result by miles, others did not foresee the drubbing of the NDA or the landslide for the Grand Alliance.</p><p>Also read- Modi, Shah, Jaitley responsible for Bihar debacle: Arun Shourie <br /></p><p>The one survey that got it right, by Axis-Ad-Print-Media (India) Limited, was not allowed to be aired by CNN-IBN and had to post their predictions on their website. They had predicted 169-183 seats for the Grand Alliance and 58-70 seats for the NDA.</p><p>Today's Chankaya, which has acquired reputation for its to-the-mark prediction, especially in the last Lok Sabha polls and the Delhi Assembly elections in 2013, came out with a profuse apology for its prediction of 155 seats for the BJP-led NDA.</p><p>Also read- Meet Modi's ex-poll strategist who helped Nitish win <br /></p><p>The NDTV also apologised for the error in its forecast as well as the early trends and blamed it on incorrect data. When the folly dawned on the channel, co-founder and executive co-chairperson Prannoy Roy blamed faulty data. <br /></p><p>"The data from the fieldwork agency is normally reliable... was incorrect. And it happens. We are looking into it on what went wrong. We take the responsibility and sincerely apologise," Roy said on NDTV.</p><p>With different channels showing different trends, there was uproar on the social media. Finally, many stuck to the figures released by the Election Commission of India or Doordarshan till the picture became clear.</p><p>Also read- Bihar verdict: The issue of Bihari vs Bahari settled now, says Shatrughan Sinha </p><p>While NDTV showed that the NDA was ahead in 88 seats as against Grand Alliance in 57 of 150 seats, ABP said the NDA was leading in 75 seats while the Grand alliance was ahead in 70 seats out of 149.</p><p>An exit poll on NDTV channel gave 120 to 130 seats for the NDA and 105 to 115 to the Grand Alliance. India Today-Cicero poll predicted 113 to 127 seats for the NDA and RLSP and 111 to 123 for the Grand alliance while India TV forecast 112 to 132 seats for the JD-U led alliance and 101 to 121 for the NDA.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/exit-polls-3_180_110915090900.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/exit-polls-3_305_110915090900.jpg
</highres><caption><![CDATA[
BJP office wears a deserted look following the party's defeat in Bihar Assembly polls, in New Delhi on Sunday
]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/bihar-election-exit-polls-get-it-all-wrong/1/519703.html
]]></weburl></item><item><storyid>519702</storyid><headline><![CDATA[
NDA to face tough time in Parliament after defeat in Bihar
]]></headline><credit><![CDATA[ Amit Agnihotri ]]></credit><date>2015-11-09T03:25:08+05:30</date><city><![CDATA[ New Delhi ]]></city><courtesy><![CDATA[ Mail Today ]]></courtesy><kicker><![CDATA[
NDA's defeat in the Bihar Assembly polls could result in a washed-out winter session of Parliament, scheduled to start this month.
]]></kicker><body><![CDATA[
<p>The growing bitterness between the Congress and the BJP over rising intolerance in the country, the attack on the legacy of Jawaharlal Nehru by the saffron party, coupled with NDA's defeat in the Bihar Assembly polls could result in a washed-out winter session of Parliament, scheduled to start this month.</p><p>After the success of the grand alliance in the Bihar polls, the Congress along with its allies JD-U and RJD and the Left parties could together corner the BJPled NDA government which is keen to pass several important bills especially those related to the GST, land acquisition and real estate regulation.</p><p>RJD chief Lalu has already hinted that he would focus more on Delhi to counter BJP and let Nitish manage Bihar. Earlier, the Congress did not allow the government to run Parliament in the budget and monsoon sessions till PM Narendra Modi sacked tainted BJP leaders like External Affairs minister Sushma Swaraj and Rajasthan Chief Minister Vasundhara Raje for helping fugitive Lalit Modi and Madhya Pradesh Chief Minister Shivraj Singh Chouhan for his role in the multicrore Vyapam scam.</p><p>The Congress has already said that it will again seek accountability from the government during the winter session on Sushma lying before the Lok Sabha when she said her ministry had no knowledge of letters written by former finance minister P Chidambaram to UK chancellor of exchequer George Osborne regarding Lalit Modi's deportation. They had also charged the government of being stubborn and averse to taking the opposition on board in passing key legislations. As a result, the GST bill, real estate regulation bill and land acquisition bill remained stuck, putting a break on Modi's economic reforms agenda as he desperately sought foreign capital during his visits abroad.</p><p>Congress is miffed that the government land bill aims to negate the 2013 land takeover act passed by the previous UPA government and has raised objections to it. The party has also decided not to support the government on the national judicial appointments commission. Besides the issue of rising intolerance and pursuance of divisive politics, Congress is also angry with BJP government for trying to dilute the legacy of country's first prime minister Jawaharlal Nehru by renaming schemes under his name and reshaping the Nehru memorial museum and library.</p>
]]></body><bodyimages><image><lowres>
http://media2.intoday.in/indiatoday/images/stories/modi-story_180_110915082910.jpg
</lowres><highres>
http://media2.intoday.in/indiatoday/images/stories/modi-story_305_110915082910.jpg
</highres><caption><![CDATA[ Narendra Modi ]]></caption></image></bodyimages><weburl><![CDATA[
http://indiatoday.intoday.in/story/nda-to-face-tough-time-in-parliament-after-defeat-in-bihar/1/519702.html
]]></weburl></item></Root>    
XML;

  $xml_path = 'public://elections/assembly_election_2015/elections-stories.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function for generate elections-videos.xml feed
 */
function genrate_static_indiatoday_assembly_election_2015_videos() {
  $xml = "<Root><idsection>1087</idsection><section>bihar polls 2015</section><totalvideos>25</totalvideos><start_index>0</start_index><end_index>25</end_index><item><title>
Famous father, unknown son: Nitish junior talks to India Today
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nishant-video_180_112015062025.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nishant-video_305_112015062025.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-527719-videos.xml
</url><create_date>2015-11-20</create_date><create_datetime>2015-11-20T18:11:06+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>So Sorry: Where did BJP go wrong?</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/so-sorry-180_111715063028.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/so-sorry-305_111715063028.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-525055-videos.xml
</url><create_date>2015-11-17</create_date><create_datetime>2015-11-17T18:30:28+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Indians are still tolerant: Dalai Lama on Bihar polls
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/dalai-lama-video_180_111515022515.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/dalai-lama-video_305_111515022515.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-523463-videos.xml
</url><create_date>2015-11-15</create_date><create_datetime>2015-11-15T14:25:15+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Bihar govt formation: Nitish to take oath as CM on Nov 20
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-oath---1_180_111115114527_111215013258_111315125326.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-oath---1_305_111115114527_111215013258_111315125326.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-522255-videos.xml
</url><create_date>2015-11-13</create_date><create_datetime>2015-11-13T12:52:16+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Diwali bomb: Rahul's rocket vs Modi's dhanush</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/so-sorry-video_180_111115095312.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/so-sorry-video_305_111115095312.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-521259-videos.xml
</url><create_date>2015-11-11</create_date><create_datetime>2015-11-11T09:33:30+05:30</create_datetime><syndications>0</syndications><is_favorite>true</is_favorite></item><item><title>
Negative campaign led to BJP's defeat in Bihar: Sukhbir Badal
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/badal-video_180_111015115905.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/badal-video_305_111015115905.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-521205-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T23:39:59+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Sidelined BJP veterans tear into Modi, Shah</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/modi_180_111015104230.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/modi_305_111015104230.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-521183-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T22:42:30+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Bhagwat's statement not behind defeat in Bihar: Rajnath Singh
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/rss-video-180_111015024329.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/smog-video_305_111015024329.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520694-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T14:28:00+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
It is a suicide by the party itself: Bhola Singh on Bihar polls
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bhola-video_180_111015022607.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bhola-video_305_111015022607.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520692-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T14:24:56+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
India Today Exclusive: The Bihar govt formula revealed
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-lalu-video_180_111015012852.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-lalu-video_305_111015012852.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520649-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T13:28:02+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Nitish Kumar to take oath as Bihar's CM on Nov 20</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-oath-video_180_111015122536.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-oath-video_305_111015122536.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520594-videos.xml
</url><create_date>2015-11-10</create_date><create_datetime>2015-11-10T12:09:02+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Sensex plunges 600 points as BJP suffers massive loss in Bihar
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bse-video_180_110915115747.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bse-video_305_110915115747.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520489-videos.xml
</url><create_date>2015-11-9</create_date><create_datetime>2015-11-09T23:57:03+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Union Minister Uma Bharti targets Shatrughan Sinha for criticising BJP
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/shatrughan-sinha_180_110915064703.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/shatrughan-sinha_305_110915064703.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-520178-videos.xml
</url><create_date>2015-11-9</create_date><create_datetime>2015-11-09T18:45:33+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Bihar election taught Modi a lesson: Lalu's son</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/lalu-son-video_180_110915020201.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/lalu-son-video_305_110915020201.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519897-videos.xml
</url><create_date>2015-11-9</create_date><create_datetime>2015-11-09T14:00:29+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Grand Alliance celebrates Bihar victory</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-video_180_110815114537.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-video_305_110815114537.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519691-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T23:43:24+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Bihar election results: How the day unfolded</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bihar-polls-entire-day-video_180_110815110425.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/bihar-polls-entire-day-video_305_110815110425.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519681-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T22:59:51+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Bihar poll results a rebuke to Modi: Chidambaram</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/chidambaram-video_180_110815102242.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/chidambaram-video_305_110815102242.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519670-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T22:22:42+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>BJP will introspect Bihar defeat: Sushil Modi</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/sushil-video_180_110815063638.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/sushil-video_305_110815063638.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519507-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T18:36:38+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Bihar Results: Mulayam congratulates Nitish, Lalu</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/mulayam-video_180_110815054501.png
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/mulayam-video_305_110815054501.png
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519475-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T17:45:01+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Sonia Gandhi calls up L K Advani on his birthday</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/allaince-video_180_110815035432.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/allaince-video_305_110815035432.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519382-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T15:54:32+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
We will overthrow Fascist regime of Modi: Lalu Yadav
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-hug_180_110815034641.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitish-hug_305_110815034641.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519373-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T15:46:41+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Bihar Battle: Nitish receives congratulatory messages after a sweeping win
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitishvictory_video_180_110815032805.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/nitishvictory_video_305_110815032805.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519347-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T15:14:28+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>
Package for Bihar commitment will be fulfilled by Centre: Rajnath
</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/rajnath-video_180_110815031620.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/rajnath-video_305_110815031620.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519341-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T15:14:14+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>Delhi CM congratulates Nitish Kumar on Bihar win</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/kejriwal-video_180_110815022623.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/kejriwal-video_305_110815022623.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519319-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T14:26:23+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item><item><title>BJP, RSS can't divide people and win: Rahul Gandhi</title><mediumimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/rahul-video_180_110815021937.jpg
]]></mediumimage><thumbimage><![CDATA[
http://media2.intoday.in/indiatoday/images/stories/rahul-video_305_110815021937.jpg
]]></thumbimage><url>
http://feeds.intoday.in/elections/assembly_election_2015/elections-519311-videos.xml
</url><create_date>2015-11-8</create_date><create_datetime>2015-11-08T14:19:37+05:30</create_datetime><syndications>1</syndications><is_favorite>true</is_favorite></item></Root>";
  $xml_path = 'public://elections/assembly_election_2015/elections-videos.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function for generate static xml
 */
function genrate_static_indiatoday_assembly_election_2015_photos() {
  $xml = "<Root><idsection>117</idsection><section>elections</section><totalgalleries>25</totalgalleries><start_index>0</start_index><end_index>25</end_index><gallery><galleryid>16378</galleryid><title><![CDATA[ Nitish Kumar sworn-in as Bihar Chief Minister ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16378-photos.xml
  </url></gallery><gallery><galleryid>16312</galleryid><title><![CDATA[
  When Shatrughan 'shotgun' Sinha fired full throttle
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16312-photos.xml
  </url></gallery><gallery><galleryid>16306</galleryid><title><![CDATA[ Nitish, Lalu celebrate their win in Bihar ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16306-photos.xml
  </url></gallery><gallery><galleryid>16305</galleryid><title><![CDATA[
  Congress and JDU supporters celebrate Grand Alliance's victory in Bihar
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16305-photos.xml
  </url></gallery><gallery><galleryid>16302</galleryid><title><![CDATA[
  JD(U) supporters celebrate the Mahagathbandhans victory
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16302-photos.xml
  </url></gallery><gallery><galleryid>16301</galleryid><title><![CDATA[ Bihar Chief Minister Nitish Kumar after victory ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16301-photos.xml
  </url></gallery><gallery><galleryid>16300</galleryid><title><![CDATA[ Who congratulated Nitish Kumar? ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16300-photos.xml
  </url></gallery><gallery><galleryid>16298</galleryid><title><![CDATA[
  Celebrations begin as trends show Mahagatbandhan leading
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16298-photos.xml
  </url></gallery><gallery><galleryid>16283</galleryid><title><![CDATA[
  Bihar exit polls: Neck-and-neck for NDA and Grand Alliance
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16283-photos.xml
  </url></gallery><gallery><galleryid>16259</galleryid><title><![CDATA[ Over 57 per cent polling in fourth phase ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16259-photos.xml
  </url></gallery><gallery><galleryid>16212</galleryid><title><![CDATA[ Over 50 per cent turnout in 3rd phase ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16212-photos.xml
  </url></gallery><gallery><galleryid>16150</galleryid><title><![CDATA[
  Bihar Chief Minister Nitish Kumar at Patandevi shrine
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16150-photos.xml
  </url></gallery><gallery><galleryid>16149</galleryid><title><![CDATA[
  Bihar polls: Who is to be blamed for the price rise?
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16149-photos.xml
  </url></gallery><gallery><galleryid>16101</galleryid><title><![CDATA[
  Check out how artists await Bihar poll results for a better future of their art
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16101-photos.xml
  </url></gallery><gallery><galleryid>16097</galleryid><title><![CDATA[
  Bihar polls: Glimpse of Jitan Ram Manjhi's campaign
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16097-photos.xml
  </url></gallery><gallery><galleryid>16085</galleryid><title><![CDATA[
  What do women voters have to say about Bihar battle?
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16085-photos.xml
  </url></gallery><gallery><galleryid>16083</galleryid><title><![CDATA[
  Bihar battle: Foes and friends meet over coffee in Patna airport
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16083-photos.xml
  </url></gallery><gallery><galleryid>16077</galleryid><title><![CDATA[ Ajay Devgn rally: Star power boomerangs ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16077-photos.xml
  </url></gallery><gallery><galleryid>16072</galleryid><title><![CDATA[ Bihar polls: The voters speak ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16072-photos.xml
  </url></gallery><gallery><galleryid>16068</galleryid><title><![CDATA[
  Witness Prime Minister Narendra Modi's election rally in Jehanabad
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16068-photos.xml
  </url></gallery><gallery><galleryid>16066</galleryid><title><![CDATA[
  Bihar polls: 6 Pictures of voters turnout on elections day
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16066-photos.xml
  </url></gallery><gallery><galleryid>16056</galleryid><title><![CDATA[
  Bihar elections: Battle between Modi and Nitish begins
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16056-photos.xml
  </url></gallery><gallery><galleryid>16031</galleryid><title><![CDATA[ Bihar polls: Narendra Modi in Sasaram ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16031-photos.xml
  </url></gallery><gallery><galleryid>16023</galleryid><title><![CDATA[
  Bihar election: Key numbers from ITG-Cicero pre-poll survey
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16023-photos.xml
  </url></gallery><gallery><galleryid>16020</galleryid><title><![CDATA[
  In Pics: Narendra Modi addressing a rally in Begusarai
  ]]></title><url>
  http://feeds.intoday.in/elections/assembly_election_2015/elections-16020-photos.xml
  </url></gallery></Root>";
  $xml_path = 'public://elections/assembly_election_2015/elections-photos.xml';
  $fp = fopen($xml_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * Function for generate aboutus xml static
 */
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

/**
 * Function is for generate Ads_ad xml static
 */
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

/**
 * Function is for generate COntact us static feed
 */
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

/**
 * Function for generate version control xml static
 */
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

/**
 * Function for generate android version control xml
 */
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

/**
 * Function for event static xml
 */
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
