<%@ page contentType="html; charset=ISO-8859-1" %>
<%@ page import="java.sql.*"%>
<%@ page import="java.util.*"%>
<%@ page import="com.itgd.conn.Dbconnection"%>
<%@page import="java.io.IOException"%>
<%@page import="java.io.File"%>
<%@page import="java.io.FileOutputStream"%>
<%@page import="java.io.IOException"%>
<%@include file="../global.jsp"%>
<%
//misc from 
Connection cn_misc = null;
Statement st_misc = null;
PreparedStatement pstmt_misc = null;
ResultSet rs_misc = null;
int contentIdMisc=0;
String storiesToGenerateMisc="";
StringBuffer miscHeadlinesSB= null;
//misc till
Connection cn=null;
Statement st = null;
PreparedStatement pstmt = null;
ResultSet rs=null;
String selectQueryII="";
String selectQuery="";
int contentId=0;
int totalArticles=10;
int totalArticlesFetched=0;
int fileGenerated=0;
String LATEST_OFTHE_LOT="268";
String storiesToGenerate="0";
String relatedCheckTags = "";
String relatedStory = "NO";
String relatedPhoto = "NO";
String relatedVideo = "NO";
/* === XML GENERATE VARIABLES === */
int counter=0;
StringBuffer homepageManagerSB=null;
String fileName="notification";
String xmllocalpath = "";
String excelData="";
File sourceFile = null;

/* === XML GENERATE VARIABLES === */
int cutoffDays = 0;
String cutoffCheck = "";
String content_type="";
int appId=0;
String deviceId="";
String websiteId="";
String deviceName="all";

//Application ID 1-India Today 4-India Today Ipad
if(request.getParameter("app_id") != null)
	appId = Integer.parseInt(request.getParameter("app_id"));
//1 - iOS; 2 - BB; 3 - Android; 4 - Nokia ASHA; 5 - Windows Phone; 7 - OS X; 8 - Windows 8; 9 - Amazon; 10 - Safari; 11 - Chrome	
if(request.getParameter("device") != null)
	deviceId = request.getParameter("device");
//website id at-Aajtak it-india today
if(request.getParameter("website") != null) 
	websiteId = request.getParameter("website");



deviceId="0,"+deviceId;


String[] DEVICE_CATIDS = null;

try
{
	Class.forName("com.mysql.jdbc.Driver");
	//cn = DriverManager.getConnection("jdbc:mysql:\\10.5.0.105\\:3306/notificationhub","itgd_office","!tgd_0ff@73"); 
	//cn = DriverManager.getConnection("jdbc:mysql://10.5.0.105:3306/notificationhub","itgd_office","!tgd_0ff@73");
	cn = DriverManager.getConnection("jdbc:mysql://localhost:3306/notificationhub","root","root"); 
	//Dbconnection adminConn = Dbconnection.getInstance("pushwoosh");
	//cn = adminConn.getConnection("pushwoosh");
	
	PreparedStatement hmstmt = null;
	ResultSet hmrs=null;

	if(appId==1){
	if(deviceId != null && !deviceId.equals("")){
	 
	 if(deviceId.contains(",")){
	 DEVICE_CATIDS = deviceId.split("\\,");
	int devicecatidLength=0;
	devicecatidLength=DEVICE_CATIDS.length;
	for(int ctr=0;ctr<devicecatidLength;ctr++)
	{		
			
			counter=0;
			homepageManagerSB=new StringBuffer();
			fileName="notification";
			if(DEVICE_CATIDS[ctr].equals("1"))
			deviceName="ios";
			else if(DEVICE_CATIDS[ctr].equals("2"))
			deviceName="bb";
			else if(DEVICE_CATIDS[ctr].equals("3"))
			deviceName="android";
			else if(DEVICE_CATIDS[ctr].equals("4"))
			deviceName="nokiaasha";
			else if(DEVICE_CATIDS[ctr].equals("5"))
			deviceName="windowsphone";
			else if(DEVICE_CATIDS[ctr].equals("7"))
			deviceName="osx";
			else if(DEVICE_CATIDS[ctr].equals("8"))
			deviceName="windows8";
			else if(DEVICE_CATIDS[ctr].equals("9"))
			deviceName="amazon";
			else if(DEVICE_CATIDS[ctr].equals("10"))
			deviceName="safari";
			else if(DEVICE_CATIDS[ctr].equals("11"))
			deviceName="chrome";
			
			fileName=fileName+"_"+deviceName;
			
			try
			{
				String sselectQuery ="";
				//String sselectQuery ="SELECT `section_name`,`section_url`,content_id, content_id,DATE_FORMAT(modified,'%M %e, %Y')as created,DATE_FORMAT(modified, '%Y-%m-%dT%T+05:30') as createddatetime, title, introtext, published, kicker_image,   mobile_image, medium_image, large_kicker_image, extralarge_image, ordering, content_type, sef_url, byline,  city FROM jos_homepage_manager WHERE  published=1 AND  display_zone='home_left'  AND content_type='0' GROUP BY id ORDER BY ordering LIMIT 1";
				
				//String sselectQuery ="SELECT `content_id`,`message`,`message_url`,`android_banner`,DATE_FORMAT(`modified_datetime`,'%M %e, %Y')AS created,DATE_FORMAT(`modified_datetime`, '%Y-%m-%dT%T+05:30') AS createddatetime,`android_custom_icon`,`content_type` FROM `message` WHERE `published`=1 AND STATUS=1 AND `app_id`='6' AND DATE(`published_datetime`)=CURDATE()  ORDER BY `id` DESC"; 
			if(DEVICE_CATIDS[ctr].equals("0")){
			 sselectQuery ="SELECT  IFNULL(android_header,'')android_header,IFNULL(category,'')category,IFNULL(android_custom_icon,'')android_custom_icon,`content_id`,`message`,`message_url`,`android_banner`,DATE_FORMAT(`modified_datetime`,'%M %e, %Y')AS created,DATE_FORMAT(`modified_datetime`, '%Y-%m-%d %T +05:30') AS createddatetime,`content_type` FROM `message` WHERE `published`=1 AND STATUS=1 AND `app_id` in ('1','4')   ORDER BY `id` DESC LIMIT 25";
			}else{
			 sselectQuery ="SELECT  IFNULL(android_header,'')android_header,IFNULL(category,'')category,IFNULL(android_custom_icon,'')android_custom_icon,`content_id`,`message`,`message_url`,`android_banner`,DATE_FORMAT(`modified_datetime`,'%M %e, %Y')AS created,DATE_FORMAT(`modified_datetime`, '%Y-%m-%d %T +05:30') AS createddatetime,`content_type` FROM `message` WHERE `published`=1 AND STATUS=1 AND `app_id`=1 and devices like '%"+DEVICE_CATIDS[ctr]+"%'   ORDER BY `id` DESC LIMIT 25";
			
			}	
				
				//out.println(sselectQuery);
				hmstmt = cn.prepareStatement(sselectQuery);
				hmrs = hmstmt.executeQuery();
				while(hmrs.next()){
					contentId = hmrs.getInt("content_id");
					content_type=hmrs.getString("content_type");
					String ah = hmrs.getString("android_header");
					String catgry=hmrs.getString("category");
					String and_icon=hmrs.getString("android_custom_icon");
					homepageManagerSB.append("<article>");					
					homepageManagerSB.append("<title><![CDATA["+hmrs.getString("message").replaceAll("\\<.*?>","")+"]]></title>");
					homepageManagerSB.append("<header>"+ah+"</header>");
					homepageManagerSB.append("<section_name>"+catgry+"</section_name>");
					homepageManagerSB.append("<thumbimage>"+and_icon+"</thumbimage><kickerimage>"+and_icon+"</kickerimage>");
					if(contentId>0){		
					String webUrl=getContentUrl(""+contentId,content_type);
					if(webUrl!=null&&!webUrl.equals("")){
					homepageManagerSB.append("<url>"+content_type+contentId+FILE_EXT+"</url>");					
					homepageManagerSB.append("<weburl><![CDATA[http://m.indiatoday.in/"+webUrl+"]]></weburl>");	
					}else{
					homepageManagerSB.append("<url></url><weburl></weburl>");
					}				
					}else{
					homepageManagerSB.append("<url></url><weburl></weburl>");
					}
					homepageManagerSB.append("<create_date>"+hmrs.getString("created")+"</create_date>");
					homepageManagerSB.append("<create_datetime>"+hmrs.getString("createddatetime")+"</create_datetime>");					
					homepageManagerSB.append("</article>");
					if(contentId>0){
					if(content_type.equals("photo")){
					
					//out.println("photo@@@@@@@--"+contentId);
					getPhotoStory("0,"+contentId);
					}else if(content_type.equals("video")){
					getVideos(""+contentId);
					//out.println("video@@@@@@@--"+contentId);
					}else if(content_type.equals("story")){
					getStory("0,"+contentId);
					//out.println("stopry@@@@@@@--"+contentId);
					}
								
					}
					counter++;
					//out.println("push notification  Data fetching Error->");
				}
				
				} catch(Exception ex) {
				out.println("1 nokia-wp-it/stories/notification.jsp push notification  Data fetching Error-> "+ex.toString());
			} finally{
				if(hmstmt!=null)
					hmstmt.close();
				if(hmrs!=null)
					hmrs.close();
			}
		
	
	if(counter>0){

	/* ======= XML GENERATING CODE ================ */
	try {
		if(totalArticlesFetched<totalArticles)
		totalArticles=totalArticlesFetched;
		excelData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
		excelData=excelData+"<idsection>1</idsection><section>Notifications</section>";
		excelData=excelData+"<totalarticle>"+totalArticles+"</totalarticle><start_index>0</start_index>";
		excelData=excelData+"<end_index>"+totalArticlesFetched+"</end_index>";
		excelData=excelData+"<footersharemsg>Shared via India Today News App  http://bit.ly/1DBXcjS</footersharemsg>";		
		excelData=excelData+homepageManagerSB.toString();
		excelData=excelData+"</Root>";
		sourceFile = new File("");
		if (sourceFile.exists()) {
			File file = (new File(XMLPATH_NOTIFICATIONS));
			fileName = fileName.replaceAll("%20", "");
			xmllocalpath = XMLPATH_NOTIFICATIONS + fileName + FILE_EXT; 
			FileOutputStream outLN = new FileOutputStream(xmllocalpath);
			outLN.write(excelData.getBytes());
			outLN.close();
		} else {
			xmllocalpath = XMLPATH_NOTIFICATIONS + fileName + FILE_EXT;
			FileOutputStream fos1 = new FileOutputStream(xmllocalpath);
			fos1.write(excelData.getBytes());
			fos1.flush();
			fos1.close();
		}	
		
		fileGenerated=1;
		
	} catch (IOException ioe) {
		if(fileGenerated==0)
			out.println("2 nokia-wp-it/stories/notification.jsp push notification-Home.jsp TEXT type -"+xmllocalpath+"- file generation Error"+ioe.toString());
	}

	/* ======= XML GENERATING CODE ================ */
	}
	}
	}}
	}else if(appId==4){
	
		fileName="notification_ipad";
			int counter1=0;
			try
			{
				//String sselectQuery ="SELECT `section_name`,`section_url`,content_id, content_id,DATE_FORMAT(modified,'%M %e, %Y')as created,DATE_FORMAT(modified, '%Y-%m-%dT%T+05:30') as createddatetime, title, introtext, published, kicker_image,   mobile_image, medium_image, large_kicker_image, extralarge_image, ordering, content_type, sef_url, byline,  city FROM jos_homepage_manager WHERE  published=1 AND  display_zone='home_left'  AND content_type='0' GROUP BY id ORDER BY ordering LIMIT 1";
				
				//String sselectQuery ="SELECT `content_id`,`message`,`message_url`,`android_banner`,DATE_FORMAT(`modified_datetime`,'%M %e, %Y')AS created,DATE_FORMAT(`modified_datetime`, '%Y-%m-%dT%T+05:30') AS createddatetime,`android_custom_icon`,`content_type` FROM `message` WHERE `published`=1 AND STATUS=1 AND `app_id`='6' AND DATE(`published_datetime`)=CURDATE()  ORDER BY `id` DESC"; 

				String sselectQuery ="SELECT  IFNULL(android_header,'')android_header,IFNULL(category,'')category,IFNULL(android_custom_icon,'')android_custom_icon,`content_id`,`message`,`message_url`,`android_banner`,DATE_FORMAT(`modified_datetime`,'%M %e, %Y')AS created,DATE_FORMAT(`modified_datetime`, '%Y-%m-%d %T +05:30') AS createddatetime,`content_type` FROM `message` WHERE `published`=1 AND STATUS=1 AND `app_id` in ('4','6')   ORDER BY `id` DESC LIMIT 25";
				
				//out.print("sselectQuery-->"+sselectQuery);
				hmstmt = cn.prepareStatement(sselectQuery);
				hmrs = hmstmt.executeQuery();
				
				
				while(hmrs.next()){
					contentId = hmrs.getInt("content_id");
					content_type=hmrs.getString("content_type");
					String ah = hmrs.getString("android_header");
					String catgry=hmrs.getString("category");
					String and_icon=hmrs.getString("android_custom_icon");
					homepageManagerSB.append("<header>"+ah+"</header>");
					homepageManagerSB.append("<section_name>"+catgry+"</section_name>");
					homepageManagerSB.append("<thumbimage>"+and_icon+"</thumbimage><kickerimage>"+and_icon+"</kickerimage>");
					homepageManagerSB.append("<article>");					
					homepageManagerSB.append("<title><![CDATA["+hmrs.getString("message").replaceAll("\\<.*?>","")+"]]></title>");
					homepageManagerSB.append("<thumbimage></thumbimage><kickerimage></kickerimage>");
					if(contentId>0){		
					homepageManagerSB.append("<url>"+content_type+contentId+FILE_EXT+"</url>");
					}
					homepageManagerSB.append("<create_date>"+hmrs.getString("created")+"</create_date>");
					homepageManagerSB.append("<create_datetime>"+hmrs.getString("createddatetime")+"</create_datetime>");					
					homepageManagerSB.append("</article>");
					if(contentId>0){
					if(content_type.equals("photo")){
					
					//out.println("photo@@@@@@@--"+contentId);
					getPhotoStory("0,"+contentId);
					}else if(content_type.equals("video")){
					getVideos("0,"+contentId);
					//out.println("video@@@@@@@--"+contentId);
					}else if(content_type.equals("story")){
					getStory("0,"+contentId);
					//out.println("stopry@@@@@@@--"+contentId);
					}
								
					}
					counter1++;
				}
				
				} catch(Exception ex) {
				ex.printStackTrace();
				out.println("3 nokia-wp-it/stories/notification.jsp push notification  Data fetching Error-> "+ex.toString());
			} finally{
				if(hmstmt!=null)
					hmstmt.close();
				if(hmrs!=null)
					hmrs.close();
			}
		
	
		if(counter1>0){

	/* ======= XML GENERATING CODE ================ */
	try {
		if(totalArticlesFetched<totalArticles)
		totalArticles=totalArticlesFetched;
		excelData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
		excelData=excelData+"<idsection>1</idsection><section>Notifications</section>";
		excelData=excelData+"<totalarticle>"+totalArticles+"</totalarticle><start_index>0</start_index>";
		excelData=excelData+"<end_index>"+totalArticlesFetched+"</end_index>";	
		excelData=excelData+"<footersharemsg>Shared via India Today News App  http://bit.ly/1DBXcjS</footersharemsg>";		
		excelData=excelData+homepageManagerSB.toString();
		excelData=excelData+"</Root>";
		sourceFile = new File("");
		if (sourceFile.exists()) {
			File file = (new File(XMLPATH_NOTIFICATIONS));
			fileName = fileName.replaceAll("%20", "");
			xmllocalpath = XMLPATH_NOTIFICATIONS + fileName + FILE_EXT; 
			FileOutputStream outLN = new FileOutputStream(xmllocalpath);
			outLN.write(excelData.getBytes());
			outLN.close();
		} else {
			xmllocalpath = XMLPATH_NOTIFICATIONS + fileName + FILE_EXT;
			FileOutputStream fos1 = new FileOutputStream(xmllocalpath);
			fos1.write(excelData.getBytes());
			fos1.flush();
			fos1.close();
		}	
		
		fileGenerated=1;
		
	} catch (IOException ioe) {
		if(fileGenerated==0)
			out.println("4 nokia-wp-it/stories/notification.jsp push notification-Home.jsp TEXT type -"+xmllocalpath+"- file generation Error"+ioe.toString());
	}

	/* ======= XML GENERATING CODE ================ */
	}
	
	
	
	}
	
	if(fileGenerated==1)
			out.println("1");
			
} catch(Exception ex) {
	out.println("5  nokia-wp-it/stories/notification.jsp Problem in push notification-Home.jsp , some problem with server -> "+ex.toString());
} finally {
	if(cn!=null)
		cn.close();
}
%>

<%!
public void getPhotoStory(String gids){	
	Connection cn1=null;
	Statement st = null;
	PreparedStatement pstmt = null;
	ResultSet rs=null;
	String selectQuery="";
	String headline="";
	int contentId=0;
	int catId= 0;
	String URL = "";
	
	int totalArticlesFetched=0;
	String contentIds[] = gids.split(",");
	/* === XML GENERATE VARIABLES === */
	StringBuffer sb = null;
	String fileName="";
	String xmlCreationPath = "";
	String excelData="";
	File sourceFile = null;
	String catName="";
	String imageId="";
	String photoCaption="";
	int fileGenerated=0;
		String rselectQuery ="";
	int commentcount = 0;

	/* === XML GENERATE VARIABLES === */
	try
	{
		Dbconnection adminConn =null;
		adminConn = Dbconnection.getInstance("indiatoday_slave");
		cn1 = adminConn.getConnection("indiatoday_slave");
		int contentidLength=0;
		contentidLength=contentIds.length;
		for(int ctrContent=0; ctrContent < contentidLength; ctrContent++)
		{
			try
			{
				//selectQuery ="SELECT jg.sef_url,jpg.id as imageIdd,jpg.photo_caption as byline, jpg.photo_small_name as photoSmallImage,jpg.photo_name as photoLargeImage,jpg.photo_title as photoCaption, jc.id as imageId, jc.categoryname as catName, jg.id,jg.small_image as thumbImage, jg.Gallery_name,jg.photo_category FROM jos_gallerynames jg, jos_photocategories jc ,jos_photogallery jpg where photo_category='"+sectionId+"' and jg.id="+contentIds[ctrContent]+" and jg.id=jpg.gallery_id and  photo_category=jc.id order by jg.ordering desc";
				selectQuery ="SELECT jg.sef_url,jpg.id as imageIdd,jpg.photo_caption as byline, jpg.photo_small_name as photoSmallImage,jpg.photo_name as photoLargeImage,jpg.photo_title as photoCaption, jc.id as imageId, jc.categoryname as catName, jg.id,jg.small_image as thumbImage, jg.Gallery_name,jg.photo_category FROM jos_gallerynames jg, jos_photocategories jc ,jos_photogallery jpg where jg.id="+contentIds[ctrContent]+" and jg.id=jpg.gallery_id and  photo_category=jc.id and jg.published=1 and jpg.enable=1  order by jg.ordering,jpg.id desc";
				pstmt = cn1.prepareStatement(selectQuery);
				rs = pstmt.executeQuery();
				rs.last();
				int rowcount = rs.getRow();
				totalArticlesFetched=rowcount;	
				rs.beforeFirst(); 
				sb = new StringBuffer();	
				while(rs.next()){
					catName = rs.getString("catName");
					contentId = rs.getInt("id");
					catId = rs.getInt("photo_category");
					imageId = rs.getString("imageId");
					URL = replaceSpCharacters(rs.getString("sef_url"));
					headline =  replaceSpCharacters(rs.getString("Gallery_name"));
					photoCaption = replaceSpCharacters(rs.getString("photoCaption"));

					sb.append("<item> <imageid>"+rs.getString("imageIdd")+"</imageid> <image><![CDATA["+GALLERY_IMG_PATH+rs.getString("photoSmallImage")+"]]></image><largeimage><![CDATA["+GALLERY_IMG_PATH+rs.getString("photoLargeImage")+"]]></largeimage><caption><![CDATA["+photoCaption.replaceAll("\\<.*?>","")+"]]> </caption><byline>"+rs.getString("byline")+"</byline> </item>");
				}
				//related content start
				PreparedStatement rpstmt = null;
				ResultSet rrs=null;
				StringBuffer relatedTagsComplete = new StringBuffer();
				StringBuffer relatedTagsStory = new StringBuffer();
				StringBuffer relatedTagsPhoto = new StringBuffer();
				StringBuffer relatedTagsVideo = new StringBuffer();
				try
				{
					rselectQuery ="SELECT c.mp4_flag,s.related_article_id, s.related_title, s.related_type, s.related_order, s.related_section_id, c.large_kicker_image as mobile_image, c.title FROM jos_related_stories s,jos_content c where c.id=s.related_article_id and c.state=1 and s.article_id ="+contentId+" and related_type != 'photo' and c.title NOT LIKE '%<a herf=%' order by s.related_type, s.related_order, s.related_article_id";
					rpstmt = cn1.prepareStatement(rselectQuery);
					rrs = rpstmt.executeQuery();
					while(rrs.next()){
						if(rrs.getString("related_type").equals("text")) {
							relatedTagsStory.append("<story><title><![CDATA["+replaceSpCharacters(rrs.getString("title"))+"]]></title><url>rstory"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
							if(rrs.getString("mobile_image")!=null && !rrs.getString("mobile_image").equals("null")) {
								relatedTagsStory.append(KICKER_IMG_PATH+rrs.getString("mobile_image"));
							}
							relatedTagsStory.append("</thumbimage></story>");
						}
						if(rrs.getString("related_type").equals("video") && rrs.getInt("mp4_flag")==1) {
							relatedTagsVideo.append("<video><title><![CDATA["+replaceSpCharacters(rrs.getString("title"))+"]]></title><url>rvideo"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
							if(rrs.getString("mobile_image")!=null && !rrs.getString("mobile_image").equals("null")) {
								relatedTagsVideo.append(GALLERY_IMG_PATH+rrs.getString("mobile_image"));
							}
							relatedTagsVideo.append("</thumbimage></video>");
							//getRelatedVideo(Integer.parseInt(rrs.getString("related_article_id")),Integer.parseInt(rrs.getString("related_section_id")));
						}
					}
				if(relatedTagsStory.toString().trim().length() == 0) {
					relatedTagsStory.append("<story><title></title><url></url><thumbimage></thumbimage></story>");
				}
				if(relatedTagsVideo.toString().trim().length() == 0) {
					relatedTagsVideo.append("<video><title></title><url></url><thumbimage></thumbimage></video>");
				}

					rrs=null;
					rselectQuery="";
					rselectQuery ="SELECT s.related_article_id, s.related_title, s.related_type, s.related_order,s.related_section_id,  p.photo_small_name FROM jos_related_stories s,jos_gallerynames g, jos_photogallery p where s.related_type = 'photo' and g.published=1 and s.article_id="+contentId+" and g.id=s.related_article_id and g.id=p.gallery_id  group by s.related_article_id order by s.related_order, s.related_article_id"; 
					rpstmt = cn1.prepareStatement(rselectQuery);
					rrs = rpstmt.executeQuery();
					while(rrs.next()){
							relatedTagsPhoto.append("<photo><title><![CDATA["+rrs.getString("related_title")+"]]></title><url>rphoto"+rrs.getString("related_article_id")+FILE_EXT+"</url>");
							relatedTagsPhoto.append("<thumbimage>");
							if(rrs.getString("photo_small_name")!=null && !rrs.getString("photo_small_name").equals("null") && !rrs.getString("photo_small_name").equals(""))
								relatedTagsPhoto.append(GALLERY_IMG_PATH+rrs.getString("photo_small_name"));
							relatedTagsPhoto.append("</thumbimage></photo>");
							//getPhotoStories(Integer.parseInt(rrs.getString("related_article_id")),Integer.parseInt(rrs.getString("related_section_id")));
					}
				} catch(Exception ex) {
					System.out.println("7 nokia-wp-it/stories/notification.jsp nokia-relatedContent photos.jsp Data fetching Error-> "+ex.toString());
				} finally{
					if(rpstmt!=null)
						rpstmt.close();
					if(rrs!=null)
						rrs.close();
				}
				if(relatedTagsPhoto.toString().trim().length() == 0) {
					relatedTagsPhoto.append("<photo><title></title><url></url><thumbimage></thumbimage></photo>");
				}
				relatedTagsComplete.append("<related><stories>"+relatedTagsStory+"</stories><photos>"+relatedTagsPhoto+"</photos><videos>"+relatedTagsVideo+"</videos></related>");
				sb.append(relatedTagsComplete);
				//related content ends

								//comment start
				rrs=null;
				rselectQuery="";
				StringBuffer commentTagsComplete = new StringBuffer();
				commentTagsComplete.append("<comments>");
				try
				{
					rselectQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime, date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_content c where a.article_id="+contentId+" and a.content_type='photo' and a.article_id=c.id and a.state=1 and c.state=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
					rpstmt = cn1.prepareStatement(rselectQuery);
					rrs = rpstmt.executeQuery();
					commentcount = 0;
					rrs.last();
					commentcount=rrs.getRow();
					rrs.beforeFirst();
					//System.out.println("commentcount->"+commentcount);
					while(rrs.next()){
							commentTagsComplete.append("<comment>");
							if(rrs.getString("comment")!=null && !rrs.getString("comment").equals("null")) {
								commentTagsComplete.append("<commenttext><![CDATA["+rrs.getString("comment")+"]]></commenttext>");
							} else {
								commentTagsComplete.append("<commenttext></commenttext>");
							}
							if(rrs.getString("fname")!=null && !rrs.getString("fname").equals("null")) {
								commentTagsComplete.append("<name><![CDATA["+rrs.getString("fname")+"]]></name>");
							} else {
								commentTagsComplete.append("<name></name>");
							}
							if(rrs.getString("cdate")!=null && !rrs.getString("cdate").equals("null")) {
								commentTagsComplete.append("<createddate><![CDATA["+rrs.getString("cdate")+"]]></createddate>");
								commentTagsComplete.append("<createddatetime><![CDATA["+rrs.getString("cdatetime")+"]]></createddatetime>");
							} else {
								commentTagsComplete.append("<createddate></createddate>");
								commentTagsComplete.append("<createddatetime></createddatetime>");
							}
							if(rrs.getString("email")!=null && !rrs.getString("email").equals("null") && rrs.getInt("display_emailid")==1) {
								commentTagsComplete.append("<email><![CDATA["+rrs.getString("email")+"]]></email>");
							} else {
								commentTagsComplete.append("<email></email>");
							}
							commentTagsComplete.append("</comment>");

					}
				} catch(Exception ex) {
					System.out.println("8 nokia-wp-it/stories/notification.jsp nokia-comment photos.jsp Data fetching Error-> "+ex.toString());
				} finally{
					if(rpstmt!=null)
						rpstmt.close();
					if(rrs!=null)
						rrs.close();
				}
				if(commentcount==0) {
					commentTagsComplete.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
				}
				commentTagsComplete.append("</comments>");
				sb.append(commentTagsComplete);
				//comment ends

				/* ======= XML GENERATING CODE ================ */
				try {
					fileName="photo"+contentId;
					xmlCreationPath = "";
					excelData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
					excelData=excelData+"<idgallery>"+contentId+"</idgallery>";
					excelData=excelData+"<gallery><![CDATA["+headline+"]]></gallery>";
					excelData=excelData+"<idsection>"+catId+"</idsection>";
					excelData=excelData+"<section>"+catName+"</section>";
					excelData=excelData+"<totalpics>"+totalArticlesFetched+"</totalpics>";
					excelData=excelData+"<weburl><![CDATA["+galleryURL(URL,1,contentId)+"]]></weburl>";
					excelData=excelData+sb.toString();
					excelData=excelData+"</Root>";
					sourceFile = new File("");
					if (sourceFile.exists()) {
						File file = (new File(XMLPATH_PHOTO));
						fileName = fileName.replaceAll("%20", "");
						xmlCreationPath = XMLPATH_PHOTO + fileName + FILE_EXT; 
						FileOutputStream outLN = new FileOutputStream(xmlCreationPath);
						outLN.write(excelData.getBytes());
						outLN.close();
					} else {
						xmlCreationPath = XMLPATH_PHOTO + fileName + FILE_EXT;
						FileOutputStream fos1 = new FileOutputStream(xmlCreationPath);
						fos1.write(excelData.getBytes());
						fos1.flush();
						fos1.close();
					}
					fileGenerated=1;
				} catch (IOException ioe) {
					if(fileGenerated==0)
						System.out.println("nokia-photos-photos.jsp "+xmlCreationPath+" file creation Error ==>"+ioe.toString());
				}
			/* ======= XML GENERATING CODE ================ */
			} catch(Exception ex) {
				System.out.println("9 nokia-wp-it/stories/notification.jsp nokia-photos-photos.jsp Data fetching Error-> "+ex.toString());
			} finally{
				if(pstmt!=null)
					pstmt.close();
				if(rs!=null)
					rs.close();
					
			}
		}
		getRelatedContent(gids);
	} catch(Exception ex) {
		System.out.println("10 nokia-wp-it/stories/notification.jsp There is some Connection problem in nokia-photos-photos.jsp "+ex.toString());
	} finally{
	try{
		if(cn1!=null){
		cn1.close();
		}
		}catch(SQLException e){
		}
		}
}

public void getStory(String sIds) {
	Connection cn2=null;
	PreparedStatement pstmt = null;
	ResultSet rs=null;
	String selectQueryII="";
	String kickerImage="";
	int fileGenerated=0;
	int contentId=0;
	String catName="";
	String articleIds[] = sIds.split(",");
	//System.out.println("Article Ids->"+sIds+" -- Length->"+articleIds.length);
	/* === XML GENERATE VARIABLES === */
	StringBuffer storySB = null;
	String fileName="";
	String xmllocalpath = "";
	String excelData="";
	File sourceFile = null;
		String rselectQuery ="";
	int commentcount = 0;
		StringBuffer commentTagsCompleteR = null;

	/* === XML GENERATE VARIABLES === */
	int fileGenerated_story=0;
	try
	{
		Dbconnection adminConn =null;
		adminConn = Dbconnection.getInstance("indiatoday_slave");
		cn2 = adminConn.getConnection("indiatoday_slave");
		int articlelength=0;
		articlelength=articleIds.length;
		
		for(int ctrArticle=1; ctrArticle < articlelength; ctrArticle++)
		{
			try
			{
				selectQueryII = "SELECT js.cat_id, s.name,a.id as sid,a.sef_url,a.images as imagepath,a.title_alias as headline,a.fulltext,a.title_alias,a.courtesy,date_format( a.created,'%M %e, %Y' ) AS crt,date_format( a.created,'%Y-%m-%dT%T+05:30' ) AS crtdatetime,s.name as catname,s.id as catid, a.primary_category, a.byline, a.city,a.large_kicker_image as kickerImage,a.largeimage as largeImage FROM jos_content  a,jos_sections s,jos_article_section js  WHERE  a.id="+articleIds[ctrArticle]+" and js.article_id=a.id and js.section_id=s.id and a.id =js.article_id and js.article_id=a.id and s.id=js.section_id  order by js.ordering desc ";
			
			//System.out.println("@@@@@-->"+selectQueryII);
				pstmt = cn2.prepareStatement(selectQueryII);
				rs = pstmt.executeQuery();
				while(rs.next()){
					storySB = new StringBuffer();
					contentId = rs.getInt("sid");
					storySB.append("<item><storyid>"+contentId+" </storyid> <idsection>"+rs.getString("catid")+" </idsection> <section><![CDATA["+rs.getString("catname")+"]]> </section>");
					storySB.append("<headline ><![CDATA["+replaceSpCharacters(rs.getString("headline")).replaceAll("\\<.*?>","")+"]]></headline ><credit><![CDATA["+rs.getString("byline")+"]]> </credit><date>"+rs.getString("crt")+" </date>");

					storySB.append("<datetime>"+rs.getString("crtdatetime")+"</datetime>");
					//storySB.append("<city><![CDATA["+rs.getString("city")+"]]></city><courtesy><![CDATA["+rs.getString("courtesy").replaceAll("\\<.*?>","")+"]]></courtesy>");
					String citi=rs.getString("city");String courtesy=rs.getString("courtesy");
					if(citi!=null){
					storySB.append("<city><![CDATA["+citi+"]]></city>");
					}else{
					storySB.append("<city><![CDATA[]]></city>");	
					}
					if(courtesy!=null){
					storySB.append("<courtesy><![CDATA["+courtesy.replaceAll("\\<.*?>","")+"]]></courtesy>");
					}else{
					storySB.append("<courtesy><![CDATA[]]></courtesy>");	
					}
					//commented by Amit Tyagi// String fulltextTemp1 =  rs.getString("fulltext").replace("<P>","<p>").replace("</P>","</p>").replace("<BR>","<br>").replace("<BR />","<br />");
					//Added
					String fulltextTemp1 = rs.getString("fulltext").replace("<P>","<p>").replace("</P>","</p>").replace("<BR>","<br>").replace("<BR />","<br />").replaceAll("http://indiatoday.intoday.in","http://m.indiatoday.in");
					fulltextTemp1=fulltextTemp1.replaceAll("http://m.indiatoday.in/auto/","http://indiatoday.intoday.in/auto/");
					//sb.append("<body><![CDATA["+stripNonValidXMLCharacters(fulltextTemp.replace("funfacts","").replace("mospagebreak","").replace("</span>","").replace("{","").replace("}","").replace("mosimage","").replace("{","").replace("}","").replace("mosimage","").replace("blurb","").replace("quote","").replaceAll("<[^/bp][^>]*>|<p[a-z][^>]*>|<b[^r][^>]*>|<br[a-z][^>]*>|</[^bp]+>|</p[a-z]+>|</b[^r]+>|</br[a-z]+>","").replaceAll( "</?a[^>]*>", "" ).replaceAll("<p.*?>", "<p>").replaceAll("<hr.*?>", "").replaceAll("<b sty.*?>", "").replaceAll("</b>", "").replaceAll("<b>", "").replaceAll("</i>", "").replaceAll("<i>", "").replaceAll( "</?font[^>]*>", "" ))+"]]> </body>");
					storySB.append("<body><![CDATA["+replaceBlockWithBlockCode(stripNonValidXMLCharacters(fulltextTemp1.replace("funfacts","").replace("mospagebreak","").replace("</span>","").replace("{","").replace("}","").replace("mosimage","").replace("{","").replace("}","").replace("mosimage","").replace("blurb","").replace("relateds","").replace("quote","").replaceAll("<p[a-z][^>]*>|<br[a-z][^>]*>|</p[a-z]+>|</br[a-z]+>","").replaceAll("<p.*?>", "<p>").replaceAll("<hr.*?>", "").replaceAll("<b sty.*?>", "").replaceAll("</b>", "").replaceAll("<b>", "").replaceAll("</i>", "").replaceAll("<i>", "").replaceAll( "</?font[^>]*>", "" )))+"]]> </body>");
					storySB.append(embedVideoFunctionality(fulltextTemp1,cn2));
					//Added
					//storySB.append("<body><![CDATA["+stripNonValidXMLCharacters(fulltextTemp1.replace("funfacts","").replace("mospagebreak","").replace("</span>","").replace("{","").replace("}","").replace("mosimage","").replace("{","").replace("}","").replace("mosimage","").replace("blurb","").replace("quote","").replaceAll("<[^/bp][^>]*>|<p[a-z][^>]*>|<b[^r][^>]*>|<br[a-z][^>]*>|</[^bp]+>|</p[a-z]+>|</b[^r]+>|</br[a-z]+>","").replaceAll( "</?a[^>]*>", "" ).replaceAll("<p.*?>", "<p>").replaceAll("<hr.*?>", "").replaceAll("<b sty.*?>", "").replaceAll("</b>", "").replaceAll("<b>", "").replaceAll("</i>", "").replaceAll("<i>", "").replaceAll( "</?font[^>]*>", "" ))+"]]> </body>");
					//Commented By Amit//storySB.append("<body><![CDATA["+stripNonValidXMLCharacters(fulltextTemp1.replace("funfacts","").replace("mospagebreak","").replace("</span>","").replace("{","").replace("}","").replace("mosimage","").replace("{","").replace("}","").replace("mosimage","").replace("blurb","").replace("relateds","").replace("quote","").replaceAll("<p[a-z][^>]*>|<br[a-z][^>]*>|</p[a-z]+>|</br[a-z]+>","").replaceAll( "</?a[^>]*>", "" ).replaceAll("<p.*?>", "<p>").replaceAll("<hr.*?>", "").replaceAll("<b sty.*?>", "").replaceAll("</b>", "").replaceAll("<b>", "").replaceAll("</i>", "").replaceAll("<i>", "").replaceAll( "</?font[^>]*>", "" ))+"]]></body>");
					//storySB.append("<body><![CDATA["+replaceSpCharacters(rs.getString("fulltext")).replace("mospagebreak","").replace("{","").replace("}","").replace("mosimage","").replaceAll("<P>",".#.").replaceAll("</P>",".#.").replaceAll("<p>",".#.").replaceAll("</p>",".#.").replaceAll("\\<.*?>","").replaceAll(".#.","<p>").replaceAll(".#.","</p>").replaceAll(".#.","<P>").replaceAll(".#.","</P>")+"]]> </body>");
					//
                    if(rs.getString("kickerImage")!=null && rs.getString("kickerImage").trim().length() > 0){	
					storySB.append("<bodyimages> <image>  <lowres><![CDATA["+KICKER_IMG_PATH+rs.getString("kickerImage")+"]]></lowres>  <highres><![CDATA["+KICKER_IMG_PATH+rs.getString("kickerImage")+"]]></highres><caption></caption>  </image> </bodyimages>");
				} else {
					storySB.append("<bodyimages><image><lowres></lowres><highres></highres><caption></caption></image></bodyimages>");
				}
                    
                   

					storySB.append("<weburl><![CDATA["+storyURL(rs.getString("sef_url"),1,contentId)+"]]></weburl>");

					
					//related content start
					PreparedStatement rpstmt = null;
					ResultSet rrs=null;
					StringBuffer relatedTagsComplete = new StringBuffer();
					StringBuffer relatedTagsStory = new StringBuffer();
					StringBuffer relatedTagsPhoto = new StringBuffer();
					StringBuffer relatedTagsVideo = new StringBuffer();
					try
					{
						rselectQuery ="SELECT s.related_article_id, s.related_title, s.related_type, s.related_order, s.related_section_id, c.large_kicker_image as mobile_image, c.title,c.mp4_flag FROM jos_related_stories s,jos_content c where c.id=s.related_article_id and c.state=1 and s.article_id ="+contentId+" and related_type != 'photo' and c.title NOT LIKE '%<a href=%' order by s.related_type, s.related_order, s.related_article_id";
						rpstmt = cn2.prepareStatement(rselectQuery);
						rrs = rpstmt.executeQuery();
						while(rrs.next()){
							if(rrs.getString("related_type").equals("text")) {
								relatedTagsStory.append("<story><title><![CDATA["+rrs.getString("title").replaceAll("\\<.*?>","")+"]]></title><url>rstory"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
							if(rrs.getString("mobile_image")!=null && !rrs.getString("mobile_image").equals("null")) {
								relatedTagsStory.append(KICKER_IMG_PATH+rrs.getString("mobile_image"));
							}
							relatedTagsStory.append("</thumbimage></story>");
								//System.out.println("Related Story->"+rrs.getString("related_article_id"));
								//getRelatedStories(Integer.parseInt(rrs.getString("related_article_id")));
							}
							if(rrs.getString("related_type").equals("video") && rrs.getInt("mp4_flag")==1) {
								relatedTagsVideo.append("<video><title><![CDATA["+rrs.getString("title")+"]]></title><url>rvideo"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
								if(rrs.getString("mobile_image")!=null && !rrs.getString("mobile_image").equals("null")) {
									relatedTagsVideo.append(KICKER_IMG_PATH+rrs.getString("mobile_image"));
								}
								relatedTagsVideo.append("</thumbimage></video>");
								//System.out.println("Related Video->"+rrs.getString("related_article_id"));
								//getRelatedVideo(Integer.parseInt(rrs.getString("related_article_id")),Integer.parseInt(rrs.getString("related_section_id")));
							}
						}
				if(relatedTagsStory.toString().trim().length() == 0) {
					relatedTagsStory.append("<story><title></title><url></url><thumbimage></thumbimage></story>");
				}
				if(relatedTagsVideo.toString().trim().length() == 0) {
					relatedTagsVideo.append("<video><title></title><url></url><thumbimage></thumbimage></video>");
				}
						rrs=null;
						rselectQuery="";
						rselectQuery ="SELECT s.related_article_id, s.related_title, s.related_type, s.related_order,s.related_section_id,  p.photo_small_name FROM jos_related_stories s,jos_gallerynames g, jos_photogallery p where s.related_type = 'photo' and g.published=1 and s.article_id="+contentId+" and g.id=s.related_article_id and g.id=p.gallery_id  group by s.related_article_id order by s.related_order, s.related_article_id"; 
						rpstmt = cn2.prepareStatement(rselectQuery);
						rrs = rpstmt.executeQuery();
						while(rrs.next()){
								relatedTagsPhoto.append("<photo><title><![CDATA["+rrs.getString("related_title")+"]]></title><url>rphoto"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
								if(rrs.getString("photo_small_name")!=null && !rrs.getString("photo_small_name").equals("null") && !rrs.getString("photo_small_name").equals(""))
									relatedTagsPhoto.append(GALLERY_IMG_PATH+rrs.getString("photo_small_name"));
								relatedTagsPhoto.append("</thumbimage></photo>");
								//System.out.println("Related Photo->"+rrs.getString("related_article_id"));
								//getPhotoStories(Integer.parseInt(rrs.getString("related_article_id")),Integer.parseInt(rrs.getString("related_section_id")));
						}
					} catch(Exception ex) {
						System.out.println("11 nokia-wp-it/stories/notification.jsp nokia-relatedContent photos.jsp Data fetching Error-> "+ex.toString());
					} finally{
						if(rpstmt!=null)
							rpstmt.close();
						if(rrs!=null)
							rrs.close();
					}
				if(relatedTagsPhoto.toString().trim().length() == 0) {
					relatedTagsPhoto.append("<photo><title></title><url></url><thumbimage></thumbimage></photo>");
				}
	relatedTagsComplete.append("<related><stories>"+relatedTagsStory+"</stories><photos>"+relatedTagsPhoto+"</photos><videos>"+relatedTagsVideo+"</videos></related>");
					storySB.append(relatedTagsComplete);
					//related content ends
									//comment start
				rrs=null;
				rselectQuery="";
				commentTagsCompleteR = new StringBuffer();
				commentTagsCompleteR.append("<comments>");
				try
				{
					rselectQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime, date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_content c where a.article_id="+contentId+" and a.content_type='story' and a.article_id=c.id and a.state=1 and c.state=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
										//System.out.println(contentId + " --R rselectQuery->"+rselectQuery);

					rpstmt = cn2.prepareStatement(rselectQuery);
					rrs = rpstmt.executeQuery();
					commentcount = 0;
					rrs.last();
					commentcount=rrs.getRow();
					rrs.beforeFirst();
					while(rrs.next()){
							commentTagsCompleteR.append("<comment>");
							if(rrs.getString("comment")!=null && !rrs.getString("comment").equals("null")) {
								commentTagsCompleteR.append("<commenttext><![CDATA["+rrs.getString("comment")+"]]></commenttext>");
							} else {
								commentTagsCompleteR.append("<commenttext></commenttext>");
							}
							if(rrs.getString("fname")!=null && !rrs.getString("fname").equals("null")) {
								commentTagsCompleteR.append("<name><![CDATA["+rrs.getString("fname")+"]]></name>");
							} else {
								commentTagsCompleteR.append("<name></name>");
							}
							if(rrs.getString("cdate")!=null && !rrs.getString("cdate").equals("null")) {
								commentTagsCompleteR.append("<createddate><![CDATA["+rrs.getString("cdate")+"]]></createddate>");
								commentTagsCompleteR.append("<createddatetime><![CDATA["+rrs.getString("cdatetime")+"]]></createddatetime>");
							} else {
								commentTagsCompleteR.append("<createddate></createddate>");
								commentTagsCompleteR.append("<createddatetime></createddatetime>");
							}
							if(rrs.getString("email")!=null && !rrs.getString("email").equals("null") && rrs.getInt("display_emailid")==1) {
								commentTagsCompleteR.append("<email><![CDATA["+rrs.getString("email")+"]]></email>");
							} else {
								commentTagsCompleteR.append("<email></email>");
							}
							commentTagsCompleteR.append("</comment>");

					}
				} catch(Exception ex) {
					System.out.println("12 nokia-wp-it/stories/notification.jsp nokia-comment photos.jsp Data fetching Error-> "+ex.toString());
				} finally{
					if(rpstmt!=null)
						rpstmt.close();
					if(rrs!=null)
						rrs.close();
				}
				if(commentcount==0) {
					commentTagsCompleteR.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
				}
				commentTagsCompleteR.append("</comments>");
				//comment ends
					storySB.append(commentTagsCompleteR);

					storySB.append("</item>");
					/* ======= XML GENERATING CODE ================ */
					try {
					fileName="story"+contentId;
					xmllocalpath = "";
					excelData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
					excelData=excelData+storySB.toString();
					excelData=excelData+"</Root>";
					sourceFile = new File("");
					if (sourceFile.exists()) {
						File file = (new File(XMLPATH_STORY));
						fileName = fileName.replaceAll("%20", "");
						xmllocalpath = XMLPATH_STORY  + fileName + FILE_EXT;
						FileOutputStream outLN = new FileOutputStream(xmllocalpath);
						outLN.write(excelData.getBytes());
						outLN.close();
					} else {
						xmllocalpath = XMLPATH_STORY + fileName + FILE_EXT;
						FileOutputStream fos1 = new FileOutputStream(xmllocalpath);
						fos1.write(excelData.getBytes());
						fos1.flush();
						fos1.close();
					}
					fileGenerated_story=1;
					

					} catch (IOException ioe) {
						if(fileGenerated_story==0)
						ioe.printStackTrace();
						System.out.println("13  nokia-wp-it/stories/notification.jsp nokia-stories-story.jsp TEXT type -"+xmllocalpath+"- file generation Error"+ioe.toString());
					}
				}
			/* ======= XML GENERATING CODE ================ */
			} catch(Exception ee){
			ee.printStackTrace();
				System.out.println("15 nokia-wp-it/stories/notification.jsp Data fetching Error in nokia-wp-it/stories/notification.jsp file =>"+ee.toString());
			} finally{
				if(pstmt!=null)
					pstmt.close();
				if(rs!=null)
					rs.close();
					
			}
		}
		getRelatedContent(sIds);
	} catch(Exception ex) {
		System.out.println("16 nokia-wp-it/stories/notification.jsp Connection Error in nokia-stories-story.jsp file =>"+ex.toString());
	} finally{
	try{
		if(cn2!=null)
		cn2.close();
		}catch(SQLException e){}
	}
}

public void getVideos(String sectionId){
PreparedStatement pstmt_multibit = null;
ResultSet rs_multibit=null;
int multibitrate_flag=0;
Connection cn3=null;
PreparedStatement pstmt = null;
ResultSet rs=null;
String selectQuery="";
int contentId=0;
int catid= 0;
int video=1;
StringTokenizer vst =  null;
String openVideo = "";
int counterVideoSplitDisplay=0;
String tokenSet="";
int getVideoIndexOf =0;
int counterVideoSplit=0;
String token = "";
String tokenTemp = "";
int videoCouner=0;
int limit=25;
int fileGenerated=0;
String idsToGenerate="0";
/* === XML GENERATE VARIABLES === */
StringBuffer sb = null;
String fileName="";
String xmllocalpath = "";
String excelData="";
File sourceFile = null;
/* === XML GENERATE VARIABLES === */
	StringBuffer commentTagsComplete = null;
	int commentcount = 0;
	String rselectQuery="";
	String dateFilter = "";

try
{
	Dbconnection adminConn =null;
	adminConn = Dbconnection.getInstance("indiatoday_slave");
	cn3 = adminConn.getConnection("indiatoday_slave");
	try
	{
		selectQuery="SELECT jv.multibitrate_flag,c.story_syndication,c.metakey,c.metadesc,c.id, c.byline, c.title, c.introtext, c.sef_url as sef_url, date_format( c.created,'%Y-%m-%e' ) as pubdate, date_format( c.created,'%Y-%m-%dT%T+05:30' ) as pubdatetime, c.large_kicker_image as timage, date_format( c.created,'%M %e, %Y' ) AS crt, date_format( c.created,'%Y-%m-%dT%T+05:30' ) AS crtdatetime, art.cat_id as catId, jcat.name as catName, jv.VideoGallery_filename videoName, jv.external_url, jv.VideoGallery_foldername folderName,c.kicker_image AS kickerImage,c.large_kicker_image AS largeImage,c.kicker_image_alt_text FROM jos_content c,jos_article_section art,jos_videogallerynames jv,jos_categories jcat where  c.id = "+sectionId+" and c.mp4_flag=1 and art.section_id=c.sectionid and jcat.id=art.cat_id and art.article_id=c.id and jv.contentid=c.id and c.state=1   and jcat.published=1 GROUP BY c.id ";
		
		//System.out.println("video selectQuery->"+selectQuery);
		pstmt = cn3.prepareStatement(selectQuery);
		rs = pstmt.executeQuery();
		while(rs.next()){
			sb = new StringBuffer();
			multibitrate_flag = rs.getInt("multibitrate_flag");	
			contentId = rs.getInt("id");
			sb.append("<item>");
			sb.append("<videoid>"+contentId+"</videoid>");
			sb.append("<idsection>"+rs.getInt("catId")+"</idsection>");
			sb.append("<section><![CDATA["+rs.getString("catName")+"]]></section>");
			sb.append("<credit><![CDATA["+rs.getString("byline")+"]]></credit>");
			sb.append("<date><![CDATA["+rs.getString("crt")+"]]></date>");
			sb.append("<datetime><![CDATA["+rs.getString("crtdatetime")+"]]></datetime>");
			sb.append("<title><![CDATA["+rs.getString("title")+"]]></title>");
			sb.append("<thumbimage>");	
			if(rs.getString("timage")!=null && rs.getString("timage").trim().length() > 0) {
				sb.append("<![CDATA["+KICKER_IMG_PATH+rs.getString("timage")+"]]>");
			}
			sb.append("</thumbimage>");


			
			sb.append("<mediaid></mediaid>");
			sb.append("<uurl></uurl>");
			int fileSize=0;
			sb.append("<videoparts>");
			if(multibitrate_flag==1){
				
				
				//vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				String bitrate="_,",source_file_name="",file_path="";
				String multibitquery= "SELECT file_size,bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id="+contentId+" AND STATUS=1 and device in ('B','M')  ORDER BY ordering,bitrate";
				//String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id=536763 AND STATUS=1 ORDER BY ordering,bitrate";
				//System.out.println(multibitquery);
				pstmt_multibit = cn3.prepareStatement(multibitquery);
				rs_multibit = pstmt_multibit.executeQuery();
				rs_multibit.last();
				int rowcount_multibit = rs_multibit.getRow();
				rs_multibit.beforeFirst(); 
				HashMap<String, String> hmap=new HashMap<String,String>();
				ArrayList alist=new ArrayList<String>();
				int ordering=0,ordering_fix=0,count_multibit=0,fs=0, fs1=0,fs_size=0,fs1_size=0;
				while (rs_multibit.next()){	
				if(fs==0&&rs_multibit.getInt("bitrate")==364){fs++;fs_size=rs_multibit.getInt("file_size");}					
				if(fs1==0&&rs_multibit.getInt("bitrate")==512){fs1++;fs1_size=rs_multibit.getInt("file_size");}
				if(fs_size==0){fileSize=fs1_size;}else{fileSize=fs_size;}
					count_multibit++;
					ordering=rs_multibit.getInt("ordering");
					if(ordering_fix==0){							
						ordering_fix=ordering;
					}
					
					if(ordering != ordering_fix){
						alist.add(bitrate);bitrate="_,";
						ordering_fix=ordering;
					}
					
					bitrate=bitrate+rs_multibit.getInt("bitrate")+",";
					source_file_name=rs_multibit.getString("source_file_name");
					file_path=rs_multibit.getString("file_path");
					hmap.put(source_file_name, file_path);
					if(count_multibit==rowcount_multibit){
						alist.add(bitrate);
					}
					
				}rs_multibit=null;pstmt_multibit=null;int cneter=0;
				for (Map.Entry<String, String> entry : hmap.entrySet()) {
				String bitrateURL="http://indiatoday-vh.akamaihd.net/i/";
				String str[]=entry.getValue().toString().split("/");
				bitrateURL=bitrateURL+str[0]+"/"+str[1]+"/"+str[2]+"/";
				source_file_name=entry.getKey().replace(".mp4", alist.get(cneter).toString());cneter++;
				bitrateURL=bitrateURL+source_file_name+".mp4.csmil/master.m3u8";
				sb.append("<part>"+bitrateURL+"</part>");
			}
					
					
					
				
			
		}else{
			counterVideoSplit=0;
			if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
				vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					if(token.indexOf(".flv") > 0) {
						token = token.substring(0, token.lastIndexOf("."))+".mp4";
					}
					if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
							
										
					//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
					//if(sectionId.equals("42") || sectionId.equals("43"))
				//	if(rs.getInt("catId")==42 || rs.getInt("catId")==43 || rs.getInt("catId")==562)
				//	{
						//// INDIA ///////
						token = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
						//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
						token=token+ "/playlist.m3u8";
						sb.append("<part>"+token+"</part>");
						
				//	}else{ 
						//// NOT INDIA ///////
				//		sb.append("<part>"+token+"</part>");
				//	}
							
					
					counterVideoSplit++;	
				}
			} else {
				vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
					if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					
					//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
				//	if(sectionId.equals("42") || sectionId.equals("43") || sectionId.equals("562"))
				//	{
						//// INDIA ///////
						mp4video = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
						//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
						mp4video=mp4video+ "/playlist.m3u8";
						sb.append("<part>"+mp4video+"</part>");
						
				///	}else{ 
						//// NOT INDIA ///////
				//		sb.append("<part>"+mp4video+"</part>");
				//	}
					
					
					
					//sb.append("<part>"+mp4video+"</part>");
					counterVideoSplit++;	
				}
			}
		}	
			sb.append("</videoparts>");
			sb.append("<size_364bit>"+fileSize+"</size_364bit>");
			sb.append("<videoparts_mp4>");
			counterVideoSplit=0;
			if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
				vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					if(token.indexOf(".flv") > 0) {
						token = token.substring(0, token.lastIndexOf("."))+".mp4";
					}
					if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
						
					sb.append("<part>"+token+"</part>");					
					counterVideoSplit++;	
				}
			} else {
				vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
					if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
																				
					sb.append("<part>"+mp4video+"</part>");
					counterVideoSplit++;	
				}
			}	sb.append("</videoparts_mp4>");		
					
				sb.append("<videoparts_m3u8>");
				if(multibitrate_flag==1){
				//vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				String bitrate="_,",source_file_name="",file_path="";
				String multibitquery= "SELECT file_size,bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id="+contentId+" AND STATUS=1 and device in ('B','M') ORDER BY ordering,bitrate";
				//String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id=536763 AND STATUS=1 ORDER BY ordering,bitrate";
				//System.out.println(multibitquery);
				pstmt_multibit = cn3.prepareStatement(multibitquery);
				rs_multibit = pstmt_multibit.executeQuery();
				rs_multibit.last();
				int rowcount_multibit = rs_multibit.getRow();
				rs_multibit.beforeFirst(); 
				HashMap<String, String> hmap=new HashMap<String,String>();
				ArrayList alist=new ArrayList<String>();
				int ordering=0,ordering_fix=0,count_multibit=0,fs=0, fs1=0,fs_size=0,fs1_size=0;
				while (rs_multibit.next()){	
				if(fs==0&&rs_multibit.getInt("bitrate")==364){fs++;fs_size=rs_multibit.getInt("file_size");}					
				if(fs1==0&&rs_multibit.getInt("bitrate")==512){fs1++;fs1_size=rs_multibit.getInt("file_size");}
				if(fs_size==0){fileSize=fs1_size;}else{fileSize=fs_size;}
					count_multibit++;
					ordering=rs_multibit.getInt("ordering");
					if(ordering_fix==0){							
						ordering_fix=ordering;
					}
					
					if(ordering != ordering_fix){
						alist.add(bitrate);bitrate="_,";
						ordering_fix=ordering;
					}
					
					bitrate=bitrate+rs_multibit.getInt("bitrate")+",";
					source_file_name=rs_multibit.getString("source_file_name");
					file_path=rs_multibit.getString("file_path");
					hmap.put(source_file_name, file_path);
					if(count_multibit==rowcount_multibit){
						alist.add(bitrate);
					}
					
				}rs_multibit=null;pstmt_multibit=null;int cneter=0;
				for (Map.Entry<String, String> entry : hmap.entrySet()) {
				String bitrateURL="http://indiatoday-vh.akamaihd.net/i/";
				String str[]=entry.getValue().toString().split("/");
				bitrateURL=bitrateURL+str[0]+"/"+str[1]+"/"+str[2]+"/";
				source_file_name=entry.getKey().replace(".mp4", alist.get(cneter).toString());cneter++;
				bitrateURL=bitrateURL+source_file_name+".mp4.csmil/master.m3u8";
				sb.append("<part>"+bitrateURL+"</part>");
			}		
			
		}else{
			counterVideoSplit=0;
			if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
				vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					if(token.indexOf(".flv") > 0) {
						token = token.substring(0, token.lastIndexOf("."))+".mp4";
					}
					if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}							
										
					//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
					//if(sectionId.equals("42") || sectionId.equals("43"))
					//if(rs.getInt("catId")==42 || rs.getInt("catId")==43 || rs.getInt("catId")==562)
					//{
						//// INDIA ///////
						token = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
						//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
						token=token+ "/playlist.m3u8";
						sb.append("<part>"+token+"</part>");
						
					//}else{ 
						//// NOT INDIA ///////
						//sb.append("<part>"+token+"</part>");
					//}					
					
					counterVideoSplit++;	
				}
			} else {
				vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
					if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					
					//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
					//if(sectionId.equals("42") || sectionId.equals("43") || sectionId.equals("562"))
					//{
						//// INDIA ///////
						mp4video = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
						//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
						mp4video=mp4video+ "/playlist.m3u8";
						sb.append("<part>"+mp4video+"</part>");
						
					//}else{ 
						//// NOT INDIA ///////
						//sb.append("<part>"+mp4video+"</part>");
					//}							
					//sb.append("<part>"+mp4video+"</part>");
					counterVideoSplit++;	
				}
			}
		}
			sb.append("</videoparts_m3u8>");

			sb.append("<flvvideoparts>");
			counterVideoSplit=0;
			if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
				vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					if(token.indexOf(".mp4") > 0) {
						token = token.substring(0, token.lastIndexOf("."))+".flv";
					}
					if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					sb.append("<part>"+token+"</part>");
					counterVideoSplit++;	
				}
			} else {
				vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					String flvvideo = VIDEO_PATH_FLV+rs.getString("folderName")+"/"+token;
					if(flvvideo.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						flvvideo = flvvideo.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					sb.append("<part>"+flvvideo+"</part>");
					counterVideoSplit++;	
				}
			}
			sb.append("</flvvideoparts>");
			sb.append("<videoparts_3gp>");
			counterVideoSplit=0;
			if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
				vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					if(token.indexOf(".flv") > 0 || token.indexOf(".mp4") > 0) {
						token = token.substring(0, token.lastIndexOf("/")+1) + "3gp" + token.substring(token.lastIndexOf("/"));
						token = token.substring(0, token.lastIndexOf("."))+".3gp";
					}
					if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					sb.append("<part>"+token+"</part>");
					counterVideoSplit++;	
				}
			} else {
				vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
				while (vst.hasMoreElements())
				{
					token = vst.nextElement().toString();
					String video3gp = VIDEO_PATH+rs.getString("folderName")+"/3gp/"+token.substring(0, token.lastIndexOf("_"))+".3gp";
					if(video3gp.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
						video3gp = video3gp.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
					}
					sb.append("<part>"+video3gp+"</part>");
					counterVideoSplit++;	
				}
			}
			sb.append("</videoparts_3gp>"); 
			
			sb.append("<create_date><![CDATA["+rs.getString("pubdate")+"]]></create_date>");
			sb.append("<create_datetime><![CDATA["+rs.getString("pubdatetime")+"]]></create_datetime>");
			sb.append("<syndications>"+rs.getString("story_syndication")+"</syndications>");
			sb.append("<is_favorite>true</is_favorite>");
			sb.append("<metakeyword><![CDATA["+rs.getString("metakey")+"]]></metakeyword>");
			sb.append("<metadescription><![CDATA["+rs.getString("metadesc")+"]]></metadescription>");
			sb.append("<weburl><![CDATA["+videoURL(rs.getString("sef_url"),1,contentId)+"]]></weburl>");
			 sb.append("<bodyimages> <image>");
                sb.append("<lowres>");
                if(rs.getString("kickerImage")!=null )
                {
                sb.append("http://media2.intoday.in/indiatoday/images/stories/"+rs.getString("kickerImage"));
                }
                sb.append("</lowres>");
                sb.append("<highres>");
                if(rs.getString("largeImage")!=null ){	
				sb.append("http://media2.intoday.in/indiatoday/images/stories/"+rs.getString("largeImage"));
                }
                sb.append("</highres>");
                sb.append("<caption>");
                if(rs.getString("kicker_image_alt_text")!=null)
                {
                sb.append("<![CDATA["+rs.getString("kicker_image_alt_text").replaceAll("\\<.*?>","")+"]]>");
                }
                sb.append("</caption></image> </bodyimages>");
			PreparedStatement rpstmt = null;
			ResultSet rrs=null;
			StringBuffer relatedTagsComplete = new StringBuffer();
			StringBuffer relatedTagsStory = new StringBuffer();
			StringBuffer relatedTagsPhoto = new StringBuffer();
			StringBuffer relatedTagsVideo = new StringBuffer();
			try
			{
				rselectQuery ="SELECT s.related_article_id, s.related_title, s.related_type, s.related_order, s.related_section_id, c.large_kicker_image, c.title,c.mp4_flag FROM jos_related_stories s,jos_content c where c.id=s.related_article_id and c.state=1 and s.article_id ="+contentId+" and related_type != 'photo' order by s.related_type, s.related_order, s.related_article_id";
				rpstmt = cn3.prepareStatement(rselectQuery);
				rrs = rpstmt.executeQuery();
				while(rrs.next()){
					if(rrs.getString("related_type").equals("text")) {
						relatedTagsStory.append("<story><title><![CDATA["+rrs.getString("title")+"]]></title>");
						relatedTagsStory.append("<url>rstory"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
						if(rrs.getString("large_kicker_image")!=null && !rrs.getString("large_kicker_image").equals("null")) {
							relatedTagsStory.append("<![CDATA["+KICKER_IMG_PATH+rrs.getString("large_kicker_image")+"]]>");
						}
						relatedTagsStory.append("</thumbimage></story>");
					}
					if(rrs.getString("related_type").equals("video") && rrs.getInt("mp4_flag")==1) {
						relatedTagsVideo.append("<video><title><![CDATA["+rrs.getString("title")+"]]></title>");
						relatedTagsVideo.append("<url>rvideo"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
						if(rrs.getString("large_kicker_image")!=null && !rrs.getString("large_kicker_image").equals("null")) {
							relatedTagsVideo.append("<![CDATA["+KICKER_IMG_PATH+rrs.getString("large_kicker_image")+"]]>");
						}
						relatedTagsVideo.append("</thumbimage></video>");
					}
				}
				if(relatedTagsStory.toString().trim().length() == 0) {
					relatedTagsStory.append("<story><title></title><url></url><thumbimage></thumbimage></story>");
				}
				if(relatedTagsVideo.toString().trim().length() == 0) {
					relatedTagsVideo.append("<video><title></title><url></url><thumbimage></thumbimage></video>");
				}
				rrs=null;
				rselectQuery="";
				rselectQuery ="SELECT s.related_article_id, s.related_title, s.related_type, s.related_order,s.related_section_id,  g.small_image FROM jos_related_stories s,jos_gallerynames g, jos_photogallery p where s.related_type = 'photo' and g.published=1 and s.article_id="+contentId+" and g.id=s.related_article_id and g.id=p.gallery_id  group by s.related_article_id order by s.related_order, s.related_article_id"; 
				rpstmt = cn3.prepareStatement(rselectQuery);
				rrs = rpstmt.executeQuery();
				while(rrs.next()){
						relatedTagsPhoto.append("<photo><title><![CDATA["+rrs.getString("related_title")+"]]></title>");
						relatedTagsPhoto.append("<url>rphoto"+rrs.getString("related_article_id")+FILE_EXT+"</url><thumbimage>");
						if(rrs.getString("small_image")!=null && !rrs.getString("small_image").equals("null") && !rrs.getString("small_image").equals(""))
							relatedTagsPhoto.append("<![CDATA["+GALLERY_IMG_PATH+rrs.getString("small_image")+"]]>");
						relatedTagsPhoto.append("</thumbimage></photo>");
				}
			} catch(Exception ex) {
				System.out.println("17 nokia-wp-it/stories/notification.jspnokia-relatedContent photos.jsp Data fetching Error-> "+ex.toString());
			} finally{
				if(rpstmt!=null)
					rpstmt.close();
				if(rrs!=null)
					rrs.close();
			}
				if(relatedTagsPhoto.toString().trim().length() == 0) {
					relatedTagsPhoto.append("<photo><title></title><url></url><thumbimage></thumbimage></photo>");
				}
	relatedTagsComplete.append("<related><stories>"+relatedTagsStory+"</stories><photos>"+relatedTagsPhoto+"</photos><videos>"+relatedTagsVideo+"</videos></related>");
			sb.append(relatedTagsComplete);
			//related content ends
				//comment start
				rrs=null;
				rselectQuery="";
				commentTagsComplete = new StringBuffer();
				commentTagsComplete.append("<comments>");
				try
				{
					rselectQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime, date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_content c where a.article_id="+contentId+" and a.content_type='video' and a.article_id=c.id and a.state=1 and c.state=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
//					System.out.println("rselectQuery->"+rselectQuery);
					rpstmt = cn3.prepareStatement(rselectQuery);
					rrs = rpstmt.executeQuery();
					commentcount = 0;
					rrs.last();
					commentcount=rrs.getRow();
					//System.out.println("commentcount->"+commentcount);
					rrs.beforeFirst();
					while(rrs.next()){
							commentTagsComplete.append("<comment>");
							if(rrs.getString("comment")!=null && !rrs.getString("comment").equals("null")) {
								commentTagsComplete.append("<commenttext><![CDATA["+rrs.getString("comment")+"]]></commenttext>");
							} else {
								commentTagsComplete.append("<commenttext></commenttext>");
							}
							if(rrs.getString("fname")!=null && !rrs.getString("fname").equals("null")) {
								commentTagsComplete.append("<name><![CDATA["+rrs.getString("fname")+"]]></name>");
							} else {
								commentTagsComplete.append("<name></name>");
							}
							if(rrs.getString("cdate")!=null && !rrs.getString("cdate").equals("null")) {
								commentTagsComplete.append("<createddate><![CDATA["+rrs.getString("cdate")+"]]></createddate>");
								commentTagsComplete.append("<createddatetime><![CDATA["+rrs.getString("cdatetime")+"]]></createddatetime>");
							} else {
								commentTagsComplete.append("<createddate></createddate>");
								commentTagsComplete.append("<createddatetime></createddatetime>");
							}
							if(rrs.getString("email")!=null && !rrs.getString("email").equals("null") && rrs.getInt("display_emailid")==1) {
								commentTagsComplete.append("<email><![CDATA["+rrs.getString("email")+"]]></email>");
							} else {
								commentTagsComplete.append("<email></email>");
							}
							commentTagsComplete.append("</comment>");

					}
				} catch(Exception ex) {
					System.out.println("18 nokia-wp-it/stories/notification.jsp nokia-comment video.jsp Data fetching Error-> "+ex.toString());
				} finally{
					if(rpstmt!=null)
						rpstmt.close();
					if(rrs!=null)
						rrs.close();
				}
				if(commentcount==0) {
					commentTagsComplete.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
				}
				commentTagsComplete.append("</comments>");
				sb.append(commentTagsComplete);
				//comment ends


			sb.append("</item>");
			idsToGenerate = idsToGenerate + "," + contentId;
			/* ======= XML GENERATING CODE ================ */
			try {
				fileName="video"+contentId;
				xmllocalpath = "";
				excelData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
				excelData=excelData+sb.toString();
				excelData=excelData+"</Root>";
				sourceFile = new File("");
				if (sourceFile.exists()) {
					File file = (new File(XMLPATH_VIDEO));
					fileName = fileName.replaceAll("%20", "");
					xmllocalpath = XMLPATH_VIDEO + fileName + FILE_EXT; 
					FileOutputStream outLN = new FileOutputStream(xmllocalpath);
					outLN.write(excelData.getBytes());
					outLN.close();
				} else {
					xmllocalpath = XMLPATH_VIDEO + fileName + FILE_EXT;
					FileOutputStream fos1 = new FileOutputStream(xmllocalpath);
					fos1.write(excelData.getBytes());
					fos1.flush();
					fos1.close();
				}
				fileGenerated=1; 
			} catch (IOException ioe) {
			if(fileGenerated==0)
				System.out.println("19 nokia-wp-it/stories/notification.jsp nokia-videos-Video.jsp TEXT type -"+xmllocalpath+"- file generation Error=>"+ioe.toString());
			}
		}
		/* ======= XML GENERATING CODE ================ */
		getRelatedContent(idsToGenerate);	
	} catch(Exception ee){
			System.out.println("20 nokia-wp-it/stories/notification.jsp Error in Data fetching WP nokia videos video.jsp =>"+ee.toString());
	} finally{
		if(pstmt!=null)
			pstmt.close();
		if(rs!=null)
			rs.close();
			
	}
} catch(Exception ex) {
	System.out.println("21 nokia-wp-it/stories/notification.jsp There is some Connection problem in nokia-videos-video.jsp "+ex.toString());
} finally{
try{
if(cn3!=null)
					cn3.close();
					}catch(SQLException e){}
}
}
public String getContentUrl(String sIds,String content_type) {
	Connection cn5=null;
	PreparedStatement pstmt = null;
	ResultSet rs=null;
	String selectQueryII=null;
	int contentId=0;
	String contentUrl=null;
	try
	{
		Dbconnection adminConn = null;
		adminConn = Dbconnection.getInstance("indiatoday_slave");
		cn5 = adminConn.getConnection("indiatoday_slave");
		
			try
			{
				if(content_type.equals("photo")){
				selectQueryII = "SELECT `content_url`,`sef_url`,`id`   FROM jos_gallerynames    WHERE  id="+sIds+" and published='1' ";
				}else {
					selectQueryII = "SELECT sef_url,content_url,id  FROM jos_content    WHERE  id="+sIds+" and state='1' ";
				}					
					
				
				pstmt = cn5.prepareStatement(selectQueryII);
				rs = pstmt.executeQuery();
				while(rs.next()){					
					contentId = rs.getInt("id");
					contentUrl=rs.getString("content_url");
				}
		
			} catch(Exception ee){
			ee.printStackTrace();
				System.out.println("21  nokia-wp-it/stories/notification.jsp Data fetching Error in nokia-wp-it/stories/notification.jsp file =>"+ee.toString());
			} finally{
				if(pstmt!=null)
					pstmt.close();
				if(rs!=null)
					rs.close();
					
			}		
		
	} catch(Exception ex) {
		System.out.println("22 nokia-wp-it/stories/notification.jsp Connection Error in nokia-stories-story.jsp file =>"+ex.toString());
	} finally{
	try{
		if(cn5!=null)
		cn5.close();
		}catch(SQLException e){}
	}
	return contentUrl;
}

public void getRelatedContent(String contentids)
{	
	Connection cnr=null;
	PreparedStatement mainpstmt = null;
	ResultSet mainrs=null;
	String selectQuery="";
	String contentIds[] = contentids.split(",");
	StringBuffer commentTagsComplete = null;
	int counter=0;
	int commentcount = 0;
	PreparedStatement cpstmt = null;
	ResultSet crs=null;
	try
	{
		
Dbconnection adminConn =null;
 adminConn = Dbconnection.getInstance("indiatoday_slave");
		cnr = adminConn.getConnection("indiatoday_slave");
		int vonLength=0;
		
		vonLength=contentIds.length;
		for(int ctrContent=0; ctrContent < vonLength; ctrContent++)
		{
			try
			{
				selectQuery ="SELECT related_article_id, related_type FROM jos_related_stories where article_id="+contentIds[ctrContent];
				mainpstmt = cnr.prepareStatement(selectQuery);
				mainrs = mainpstmt.executeQuery();
				while(mainrs.next()) {
					//System.out.println("Content Id-"+contentIds[ctrContent]+" Related Id->"+mainrs.getString("related_article_id")+" Related Type->"+mainrs.getString("related_type"));
					//Related Type TEXT From
					if(mainrs.getString("related_type").equals("text")) {
						PreparedStatement pstmt = null;
						ResultSet rs = null;
						cpstmt = null;
						crs = null;
						
						try
						{
							String selectStoryQuery = "SELECT a.id as sid,a.sef_url,a.title as headline,a.fulltext,a.byline,a.city,a.courtesy,date_format( a.created,'%M %e, %Y' ) AS crt,date_format(a.created,'%Y-%m-%dT%T+05:30') AS crtdatetime, s.name as catname,s.id as catid FROM jos_content  a,jos_sections s,jos_article_section js  WHERE  a.id="+mainrs.getString("related_article_id")+" and js.article_id=a.id and js.section_id=s.id and a.is_external=0 order by js.ordering desc ";
							pstmt = cnr.prepareStatement(selectStoryQuery);
							rs = pstmt.executeQuery();
							int fileGenerated=0;
							String xmlCreationPath = "";
							while(rs.next()){
								StringBuffer sb = new StringBuffer();
								sb.append("<item><storyid>"+rs.getInt("sid")+"</storyid><idsection>"+rs.getString("catid")+"</idsection><section><![CDATA["+rs.getString("catname")+"]]></section>");
								sb.append("<headline><![CDATA["+replaceSpCharacters(rs.getString("headline")).replaceAll("\\<.*?>","")+"]]></headline><credit><![CDATA["+rs.getString("byline")+"]]></credit><date>"+rs.getString("crt")+"</date><datetime>"+rs.getString("crtdatetime")+"</datetime>");
								sb.append("<city><![CDATA["+rs.getString("city")+"]]></city><courtesy><![CDATA["+rs.getString("courtesy")+"]]></courtesy>");
								String fulltextTemp = rs.getString("fulltext").replace("<P>","<p>").replace("</P>","</p>").replace("<BR>","<br>").replace("<BR />","<br />");
								sb.append("<body><![CDATA["+replaceBlockWithBlockCode(stripNonValidXMLCharacters(fulltextTemp.replace("funfacts","").replace("mospagebreak","").replace("</span>","").replace("{","").replace("}","").replace("mosimage","").replace("{","").replace("}","").replace("mosimage","").replace("blurb","").replace("{relateds}","").replace("quote","").replaceAll("<[^/bp][^>]*>|<p[a-z][^>]*>|<b[^r][^>]*>|<br[a-z][^>]*>|</[^bp]+>|</p[a-z]+>|</b[^r]+>|</br[a-z]+>","").replaceAll( "</?a[^>]*>", "" ).replaceAll("<p.*?>", "<p>").replaceAll("<hr.*?>", "").replaceAll("<b sty.*?>", "").replaceAll("</b>", "").replaceAll("<b>", "").replaceAll("</i>", "").replaceAll("<i>", "").replaceAll( "</?font[^>]*>", "" )))+"]]> </body>");
								sb.append(embedVideoFunctionality(fulltextTemp,cnr));
								//sb.append("<body><![CDATA["+rs.getString("fulltext").replace("mospagebreak","").replace("{","").replace("}","").replace("mosimage","").replaceAll("<P>",".#.").replaceAll("</P>",".#.").replaceAll("<p>",".#.").replaceAll("</p>",".#.").replaceAll("\\<.*?>","").replaceAll(".#.","<p>").replaceAll(".#.","</p>").replaceAll(".#.","<P>").replaceAll(".#.","</P>")+"]]> </body>");


								sb.append("<bodyimages><image><lowres></lowres><highres></highres></image></bodyimages>");
								sb.append("<weburl><![CDATA["+storyURL(rs.getString("sef_url"),1,rs.getInt("sid"))+"]]></weburl>");
								//comment start
								cpstmt = null;
								crs = null;
								commentTagsComplete = new StringBuffer();
								commentTagsComplete.append("<comments>");
								try
								{
									String cQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime, date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_content c where a.article_id="+rs.getInt("sid")+" and a.content_type='story' and a.article_id=c.id and a.state=1 and c.state=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
				//					System.out.println("rselectQuery->"+rselectQuery);
									cpstmt = cnr.prepareStatement(cQuery);
									crs = cpstmt.executeQuery();
									commentcount = 0;
									crs.last();
									commentcount=crs.getRow();
									//System.out.println("commentcount->"+commentcount);
									crs.beforeFirst();
									while(crs.next()){
											commentTagsComplete.append("<comment>");
											if(crs.getString("comment")!=null && !crs.getString("comment").equals("null")) {
												commentTagsComplete.append("<commenttext><![CDATA["+crs.getString("comment")+"]]></commenttext>");
											} else {
												commentTagsComplete.append("<commenttext></commenttext>");
											}
											if(crs.getString("fname")!=null && !crs.getString("fname").equals("null")) {
												commentTagsComplete.append("<name><![CDATA["+crs.getString("fname")+"]]></name>");
											} else {
												commentTagsComplete.append("<name></name>");
											}
											if(crs.getString("cdate")!=null && !crs.getString("cdate").equals("null")) {
												commentTagsComplete.append("<createddate><![CDATA["+crs.getString("cdate")+"]]></createddate>");
												commentTagsComplete.append("<createddatetime><![CDATA["+crs.getString("cdatetime")+"]]></createddatetime>");
											} else {
												commentTagsComplete.append("<createddate></createddate>");
												commentTagsComplete.append("<createddatetime></createddatetime>");
											}
											if(crs.getString("email")!=null && !crs.getString("email").equals("null") && crs.getInt("display_emailid")==1) {
												commentTagsComplete.append("<email><![CDATA["+crs.getString("email")+"]]></email>");
											} else {
												commentTagsComplete.append("<email></email>");
											}
											commentTagsComplete.append("</comment>");

									}
								} catch(Exception ex) {
									System.out.println("23  nokia-wp-it/stories/notification.jsp nokia-comment photos.jsp Data fetching Error-> "+ex.toString());
								} finally{
									if(cpstmt!=null)
										cpstmt.close();
									if(crs!=null)
										crs.close();
								}
								if(commentcount==0) {
									commentTagsComplete.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
								}
								commentTagsComplete.append("</comments>");
								sb.append(commentTagsComplete);
								//comment ends



								sb.append("</item>");
								//Related Story XML Generating Code Starts
								
								try {
									
									String relatedStoryData="";
									File sourceFile = null;
									
									String fileName="rstory"+rs.getInt("sid");
									relatedStoryData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
									relatedStoryData=relatedStoryData+sb.toString();
									relatedStoryData=relatedStoryData+"</Root>";
									sourceFile = new File("");
									if (sourceFile.exists()) {
										File file = (new File(XMLPATH_STORY));
										fileName = fileName.replaceAll("%20", "");
										xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT; 
										FileOutputStream outLN = new FileOutputStream(xmlCreationPath);
										outLN.write(relatedStoryData.getBytes());
										outLN.close();
										
									} else {
										xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT;
										FileOutputStream fos1 = new FileOutputStream(xmlCreationPath);
										fos1.write(relatedStoryData.getBytes());
										fos1.flush();
										fos1.close();
										
									}
									fileGenerated=1;
									
								} catch (IOException ioe) {
									if(fileGenerated==0)
										System.out.println("nokia-stories-related_content.jsp TEXT type -"+xmlCreationPath+"- file generation Error");
								}
								//Related Story XML Generating Code Ends
							}
						} catch(Exception ee) {
							System.out.println("24 nokia-wp-it/stories/notification.jsp nokia.war related_content.jsp Related Story fetching Error-> "+ee.toString());
						} finally {
							if(pstmt!=null)
								pstmt.close();
							if(rs!=null)
								rs.close();
						}
					}
					//Related Type TEXT Till
					//Related Type VIDEO From
					if(mainrs.getString("related_type").equals("video")) {
						PreparedStatement pstmt_multibit = null;
						ResultSet rs_multibit=null;
						int multibitrate_flag=0;
						PreparedStatement pstmt = null;
						ResultSet rs=null;
						StringTokenizer vst =  null;
						int counterVideoSplitDisplay=0;
						int counterVideoSplit=0;
						String token = "";
						int fileGenerated=0;
						StringBuffer relatedVideoSB = null;
						try
						{
							String selectVideoQuery="SELECT jv.multibitrate_flag,jcat.id as catId,jcat.name as catName,c.byline,c.id,c.title,c.sef_url as sef_url,date_format( c.created,'%Y-%m-%e' ) as pubdate,date_format( c.created,'%Y-%m-%dT%T+05:30' ) as pubdatetime,c.large_kicker_image timage, jv.VideoGallery_filename videoName,jv.VideoGallery_foldername folderName,jv.external_url,date_format( c.created,'%M %e, %Y' ) AS crt, date_format( c.created,'%Y-%m-%dT%T+05:30' ) as crtdatetime FROM jos_content c,jos_article_section art,jos_videogallerynames jv,jos_categories jcat  where c.id="+mainrs.getString("related_article_id")+" and c.mp4_flag=1 and art.section_id=c.sectionid and jcat.id=art.cat_id and art.article_id=c.id and jv.contentid=c.id and c.is_external=0 order by art.ordering";

							//System.out.println("videoContent Id-> "+selectVideoQuery);
							pstmt = cnr.prepareStatement(selectVideoQuery);
							rs = pstmt.executeQuery();
							while(rs.next()){
								multibitrate_flag = rs.getInt("multibitrate_flag");
								relatedVideoSB = new StringBuffer();
								relatedVideoSB.append("<item><videoid>"+rs.getInt("id")+"</videoid><idsection>"+rs.getString("catid")+"</idsection><section><![CDATA["+rs.getString("catName")+"]]></section>"); relatedVideoSB.append("<credit><![CDATA["+rs.getString("byline")+"]]></credit><date>"+rs.getString("crt")+"</date><datetime>"+rs.getString("crtdatetime")+"</datetime><title><![CDATA["+rs.getString("title").replaceAll("\\<.*?>","")+"]]></title><thumbimage>");	
								if(!rs.getString("timage").equals("")){
									relatedVideoSB.append("<![CDATA["+KICKER_IMG_PATH+rs.getString("timage")+"]]>");
								} else {
									relatedVideoSB.append(NOIMG_URL);
								}
								relatedVideoSB.append("</thumbimage>");

								relatedVideoSB.append("<mediaid></mediaid>");
								relatedVideoSB.append("<uurl></uurl>");
								int fileSize=0;
								relatedVideoSB.append("<videoparts>");
								if(multibitrate_flag==1){	
									counterVideoSplit=0;
									if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
										//System.out.println(rs.getString("external_url"));
										vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									//	while (vst.hasMoreElements())
									//	{
										String bitrate="_,",source_file_name="",file_path="";
										String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id="+rs.getInt("id")+" AND STATUS=1 and device in ('B','M') ORDER BY ordering,bitrate";
										//String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id=536763 AND STATUS=1 ORDER BY ordering,bitrate";
										//System.out.println(multibitquery);
										pstmt_multibit = cnr.prepareStatement(multibitquery);
										rs_multibit = pstmt_multibit.executeQuery();
										rs_multibit.last();
										int rowcount_multibit = rs_multibit.getRow();
										rs_multibit.beforeFirst(); 
										HashMap<String, String> hmap=new HashMap<String,String>();
										ArrayList alist=new ArrayList<String>();
										int ordering=0,ordering_fix=0,count_multibit=0;
										while (rs_multibit.next()){						
											count_multibit++;
											ordering=rs_multibit.getInt("ordering");
											if(ordering_fix==0){							
												ordering_fix=ordering;
											}
											
											if(ordering != ordering_fix){
												alist.add(bitrate);bitrate="_,";
												ordering_fix=ordering;
											}
											
											bitrate=bitrate+rs_multibit.getInt("bitrate")+",";
											source_file_name=rs_multibit.getString("source_file_name");
											file_path=rs_multibit.getString("file_path");
											hmap.put(source_file_name, file_path);
											if(count_multibit==rowcount_multibit){
												alist.add(bitrate);
											}
											
										}rs_multibit=null;pstmt_multibit=null;int cneter=0;
										for (Map.Entry<String, String> entry : hmap.entrySet()) {
										String bitrateURL="http://indiatoday-vh.akamaihd.net/i/";
										String str[]=entry.getValue().toString().split("/");
										bitrateURL=bitrateURL+str[0]+"/"+str[1]+"/"+str[2]+"/";
										source_file_name=entry.getKey().replace(".mp4", alist.get(cneter).toString());cneter++;
										bitrateURL=bitrateURL+source_file_name+".mp4.csmil/master.m3u8";
										relatedVideoSB.append("<part>"+bitrateURL+"</part>");
									}

											//System.out.println(bitrate);
											//System.out.println(source_file_name);
											//System.out.println(bitrateURL);
											
											//token = vst.nextElement().toString();
											//String dummy = vst.nextElement().toString();
											//token=bitrateURL;
											//if(token.indexOf(".flv") > 0) {
											//	token = token.substring(0, token.lastIndexOf("."))+".mp4";
											//}
											//if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											//	token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
											//}							
																
											//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
											//if(sectionId.equals("42") || sectionId.equals("43"))
											//if(rs.getInt("catId")==42 || rs.getInt("catId")==43 || rs.getInt("catId")==562)
											//{
												//// INDIA ///////
												//token = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
												//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
												//token=token+ "/playlist.m3u8";
												//sb.append("<part>"+token+"</part>");
											//	sb.append("<part>"+bitrateURL+"</part>");
												
											//}else{ 
												//// NOT INDIA ///////
												//sb.append("<part>"+token+"</part>");
											//}					
										
											counterVideoSplit++;	
										//}
									} 
									
								}else{
								counterVideoSplit=0;
								if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
									vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										if(token.indexOf(".flv") > 0) {
											token = token.substring(0, token.lastIndexOf("."))+".mp4";
										}
										if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+token+"</part>");
										counterVideoSplit++;	
									}
								} else {
									vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
										if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+mp4video+"</part>");
										counterVideoSplit++;	
									}
								}
							}
								relatedVideoSB.append("</videoparts>");
								relatedVideoSB.append("<size_364bit>"+fileSize+"</size_364bit>");
								relatedVideoSB.append("<videoparts_mp4>");
								counterVideoSplit=0;
								if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
									vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										if(token.indexOf(".flv") > 0) {
											token = token.substring(0, token.lastIndexOf("."))+".mp4";
										}
										if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+token+"</part>");
										counterVideoSplit++;	
									}
								} else {
									vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
										if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+mp4video+"</part>");
										counterVideoSplit++;	
									}
								}
								relatedVideoSB.append("</videoparts_mp4>");
								
								relatedVideoSB.append("<videoparts_m3u8>");
								if(multibitrate_flag==1){	
									counterVideoSplit=0;
									if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
										//System.out.println(rs.getString("external_url"));
										vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									//	while (vst.hasMoreElements())
									//	{
										String bitrate="_,",source_file_name="",file_path="";
										String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id="+rs.getInt("id")+" AND STATUS=1 and device in ('B','M') ORDER BY ordering,bitrate";
										//String multibitquery= "SELECT bitrate,source_file_name,file_path,STATUS,file_duration,website,hls_domain,s3_domain,rtmp_domain,video_type,multipart_video,ordering FROM jos_multimedia WHERE content_id=536763 AND STATUS=1 ORDER BY ordering,bitrate";
										//System.out.println(multibitquery);
										pstmt_multibit = cnr.prepareStatement(multibitquery);
										rs_multibit = pstmt_multibit.executeQuery();
										rs_multibit.last();
										int rowcount_multibit = rs_multibit.getRow();
										rs_multibit.beforeFirst(); 
										HashMap<String, String> hmap=new HashMap<String,String>();
										ArrayList alist=new ArrayList<String>();
										int ordering=0,ordering_fix=0,count_multibit=0;
										while (rs_multibit.next()){						
											count_multibit++;
											ordering=rs_multibit.getInt("ordering");
											if(ordering_fix==0){							
												ordering_fix=ordering;
											}
											
											if(ordering != ordering_fix){
												alist.add(bitrate);bitrate="_,";
												ordering_fix=ordering;
											}
											
											bitrate=bitrate+rs_multibit.getInt("bitrate")+",";
											source_file_name=rs_multibit.getString("source_file_name");
											file_path=rs_multibit.getString("file_path");
											hmap.put(source_file_name, file_path);
											if(count_multibit==rowcount_multibit){
												alist.add(bitrate);
											}
											
										}rs_multibit=null;pstmt_multibit=null;int cneter=0;
										for (Map.Entry<String, String> entry : hmap.entrySet()) {
										String bitrateURL="http://indiatoday-vh.akamaihd.net/i/";
										String str[]=entry.getValue().toString().split("/");
										bitrateURL=bitrateURL+str[0]+"/"+str[1]+"/"+str[2]+"/";
										source_file_name=entry.getKey().replace(".mp4", alist.get(cneter).toString());cneter++;
										bitrateURL=bitrateURL+source_file_name+".mp4.csmil/master.m3u8";
										relatedVideoSB.append("<part>"+bitrateURL+"</part>");
									}

											//System.out.println(bitrate);
											//System.out.println(source_file_name);
											//System.out.println(bitrateURL);
											
											//token = vst.nextElement().toString();
											//String dummy = vst.nextElement().toString();
											//token=bitrateURL;
											//if(token.indexOf(".flv") > 0) {
											//	token = token.substring(0, token.lastIndexOf("."))+".mp4";
											//}
											//if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											//	token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
											//}							
																
											//////////////// MODIFIED ON 14-MAY-2015 ////////// FORM m3u8 //////////////
											//if(sectionId.equals("42") || sectionId.equals("43"))
											//if(rs.getInt("catId")==42 || rs.getInt("catId")==43 || rs.getInt("catId")==562)
											//{
												//// INDIA ///////
												//token = token.replaceAll("medias3d.intoday.in","wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3");
												//token="http://wowcloud.intoday.in/vods3/_definst_/mp4:amazons3/videodeliverys3/indiatoday/video/";
												//token=token+ "/playlist.m3u8";
												//sb.append("<part>"+token+"</part>");
											//	sb.append("<part>"+bitrateURL+"</part>");
												
											//}else{ 
												//// NOT INDIA ///////
												//sb.append("<part>"+token+"</part>");
											//}					
										
											counterVideoSplit++;	
										//}
									} 
									
								}else{
								counterVideoSplit=0;
								if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
									vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										if(token.indexOf(".flv") > 0) {
											token = token.substring(0, token.lastIndexOf("."))+".mp4";
										}
										if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+token+"</part>");
										counterVideoSplit++;	
									}
								} else {
									vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										String mp4video = VIDEO_PATH+rs.getString("folderName")+"/"+token.substring(0, token.lastIndexOf("_"))+".mp4";
										if(mp4video.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											mp4video = mp4video.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+mp4video+"</part>");
										counterVideoSplit++;	
									}
								}
							}
								relatedVideoSB.append("</videoparts_m3u8>");
								
								relatedVideoSB.append("<flvvideoparts>");
								counterVideoSplit=0;
								if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
									vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										if(token.indexOf(".mp4") > 0) {
											token = token.substring(0, token.lastIndexOf("."))+".flv";
										}

										if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+token+"</part>");
										counterVideoSplit++;	
									}
								} else {
									vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										String flvvideo = VIDEO_PATH_FLV+rs.getString("folderName")+"/"+token;
										if(flvvideo.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											flvvideo = flvvideo.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+flvvideo+"</part>");
										counterVideoSplit++;	
									}
								}
								relatedVideoSB.append("</flvvideoparts>");
								relatedVideoSB.append("<videoparts_3gp>");
								counterVideoSplit=0;
								if(rs.getString("external_url")!=null && rs.getString("external_url").trim().length() > 0) {
									vst =  new StringTokenizer(rs.getString("external_url").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										if(token.indexOf(".flv") > 0 || token.indexOf(".mp4") > 0) {
											token = token.substring(0, token.lastIndexOf("/")+1) + "3gp" + token.substring(token.lastIndexOf("/"));
											token = token.substring(0, token.lastIndexOf("."))+".3gp";
										}

										if(token.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											token = token.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+token+"</part>");
										counterVideoSplit++;	
									}
								} else {
									vst =  new StringTokenizer(rs.getString("videoName").toString(),"|");
									while (vst.hasMoreElements())
									{
										token = vst.nextElement().toString();
										String video3gp = VIDEO_PATH+rs.getString("folderName")+"/3gp/"+token.substring(0, token.lastIndexOf("_"))+".3gp";
										if(video3gp.indexOf("videodeliverys3.s3.amazonaws.com") >= 0) {
											video3gp = video3gp.replaceAll("videodeliverys3.s3.amazonaws.com", "medias3d.intoday.in");
										}
										relatedVideoSB.append("<part>"+video3gp+"</part>");
										counterVideoSplit++;	
									}
								}
								relatedVideoSB.append("</videoparts_3gp>");

								relatedVideoSB.append("<create_date>"+rs.getString("pubdate")+"</create_date><create_datetime>"+rs.getString("pubdatetime")+"</create_datetime><is_favorite>true</is_favorite><weburl>");
								relatedVideoSB.append("<![CDATA["+videoURL(replaceSpCharacters(rs.getString("sef_url")),1,rs.getInt("id"))+"]]>");
								relatedVideoSB.append("</weburl>");
								//comment start
								cpstmt = null;
								crs = null;
								commentTagsComplete = new StringBuffer();
								commentTagsComplete.append("<comments>");
								try
								{
									String cQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime,date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_content c where a.article_id="+mainrs.getString("related_article_id")+" and a.content_type='video' and a.article_id=c.id and a.state=1 and c.state=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
				//					System.out.println("rselectQuery->"+rselectQuery);
									cpstmt = cnr.prepareStatement(cQuery);
									crs = cpstmt.executeQuery();
									commentcount = 0;
									crs.last();
									commentcount=crs.getRow();
									//System.out.println("commentcount->"+commentcount);
									crs.beforeFirst();
									while(crs.next()){
											commentTagsComplete.append("<comment>");
											if(crs.getString("comment")!=null && !crs.getString("comment").equals("null")) {
												commentTagsComplete.append("<commenttext><![CDATA["+crs.getString("comment")+"]]></commenttext>");
											} else {
												commentTagsComplete.append("<commenttext></commenttext>");
											}
											if(crs.getString("fname")!=null && !crs.getString("fname").equals("null")) {
												commentTagsComplete.append("<name><![CDATA["+crs.getString("fname")+"]]></name>");
											} else {
												commentTagsComplete.append("<name></name>");
											}
											if(crs.getString("cdate")!=null && !crs.getString("cdate").equals("null")) {
												commentTagsComplete.append("<createddate><![CDATA["+crs.getString("cdate")+"]]></createddate>");
												commentTagsComplete.append("<createddatetime><![CDATA["+crs.getString("cdatetime")+"]]></createddatetime>");
											} else {
												commentTagsComplete.append("<createddate></createddate>");
												commentTagsComplete.append("<createddatetime></createddatetime>");
											}
											if(crs.getString("email")!=null && !crs.getString("email").equals("null") && crs.getInt("display_emailid")==1) {
												commentTagsComplete.append("<email><![CDATA["+crs.getString("email")+"]]></email>");
											} else {
												commentTagsComplete.append("<email></email>");
											}
											commentTagsComplete.append("</comment>");

									}
								} catch(Exception ex) {
									System.out.println("25 nokia-wp-it/stories/notification.jsp nokia-comment photos.jsp Data fetching Error-> "+ex.toString());
								} finally{
									if(cpstmt!=null)
										cpstmt.close();
									if(crs!=null)
										crs.close();
								}
								if(commentcount==0) {
									commentTagsComplete.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
								}
								commentTagsComplete.append("</comments>");
								relatedVideoSB.append(commentTagsComplete);
								//comment ends
								relatedVideoSB.append("</item>");

								
								//Related Video XML Generating Code Starts
								String xmlCreationPath = "";
								try {
									
									File sourceFile = null;
									String fileName="rvideo"+rs.getInt("id");
									String relatedVideoData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
									relatedVideoData=relatedVideoData+relatedVideoSB.toString();
									relatedVideoData=relatedVideoData+"</Root>";
									sourceFile = new File("");
									if (sourceFile.exists()) {
										File file = (new File(XMLPATH_STORY));
										fileName = fileName.replaceAll("%20", "");
										xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT; 
										FileOutputStream outLN = new FileOutputStream(xmlCreationPath);
										outLN.write(relatedVideoData.getBytes());
										outLN.close();
										
									} else {
										xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT;
										FileOutputStream fos1 = new FileOutputStream(xmlCreationPath);
										fos1.write(relatedVideoData.getBytes());
										fos1.flush();
										fos1.close();
										
									}
									fileGenerated=1;
									
								} catch (IOException ioe) {
									if(fileGenerated==0)
										System.out.println("26 nokia-wp-it/stories/notification.jsp nokia-stories-photos.jsp "+xmlCreationPath+" file creation Error");
								}
							}
							//Related Video XML Generating Code Ends
						} catch(Exception ee){
								System.out.println("27 nokia-wp-it/stories/notification.jsp nokia.war related_content.jsp Related Video fetching Error-> "+ee.toString());
						} finally {
							if(pstmt!=null)
								pstmt.close();
							if(rs!=null)
								rs.close();
						}
					}
					//Related Type VIDEO Till
					//Related Type PHOTO From
					if(mainrs.getString("related_type").equals("photo")) {
						PreparedStatement pstmt = null;
						ResultSet rs=null;
						String selectPhotoQuery="";
						int photoCtr=0;
						int contentId=0;
						int totalArticlesFetched=0;
						int fileGenerated=0;
						StringBuffer relatedPhotoSB = null;
						try
						{
							selectPhotoQuery ="SELECT jg.sef_url,jpg.id as imageIdd,jpg.photo_caption as byline, jpg.photo_small_name as photoSmallImage, jpg.photo_name as photolargeImage,jpg.photo_title as photoCaption, jc.id as imageId, jc.categoryname as catName, jg.id, jg.Gallery_name,jg.photo_category FROM jos_gallerynames jg, jos_photocategories jc ,jos_photogallery jpg where jg.id="+mainrs.getString("related_article_id")+" and jg.id=jpg.gallery_id and  photo_category=jc.id order by jg.ordering desc";
							pstmt = cnr.prepareStatement(selectPhotoQuery);
							rs = pstmt.executeQuery();
							rs.last();
							totalArticlesFetched = rs.getRow();
							rs.beforeFirst(); 
							relatedPhotoSB = new StringBuffer();	
							while(rs.next()){
								contentId = rs.getInt("id");
								if(photoCtr==0) {
									relatedPhotoSB.append("<idgallery>"+contentId+"</idgallery>");
									relatedPhotoSB.append("<gallery>"+replaceSpCharacters(rs.getString("Gallery_name")).replaceAll("\\<.*?>","")+"</gallery>");
									relatedPhotoSB.append("<idsection>"+rs.getInt("photo_category")+"</idsection>");
									relatedPhotoSB.append("<section><![CDATA["+rs.getString("catName")+"]]></section>");
									relatedPhotoSB.append("<totalpics>"+totalArticlesFetched+"</totalpics>");
									relatedPhotoSB.append("<weburl><![CDATA["+galleryURL(rs.getString("sef_url"),1,contentId)+"]]></weburl>");
								}
								relatedPhotoSB.append("<item><imageid>"+rs.getString("imageIdd")+"</imageid>"); 
								relatedPhotoSB.append("<image><![CDATA["+GALLERY_IMG_PATH+rs.getString("photoSmallImage")+"]]></image>");
								relatedPhotoSB.append("<largeimage><![CDATA["+GALLERY_IMG_PATH+rs.getString("photoLargeImage")+"]]></largeimage>");
								relatedPhotoSB.append("<caption><![CDATA["+replaceSpCharacters(rs.getString("photoCaption"))+"]]> </caption><byline><![CDATA["+rs.getString("byline")+"]]></byline></item>");
								photoCtr++;	
							}
							//Related Photo XML Generating Code Starts
								//comment start
								cpstmt = null;
								crs = null;
								commentTagsComplete = new StringBuffer();
								commentTagsComplete.append("<comments>");
								try
								{
									String cQuery ="select a.fname, a.lname, a.email,a.comment,a.display_emailid, date_format(a.created_date,'%M %e, %Y') AS cdate, date_format(a.created_date,'%H:%i IST') AS ctime, date_format(a.created_date,'%Y-%m-%dT%T+05:30') AS cdatetime from jos_comments a,jos_gallerynames c where a.article_id="+mainrs.getString("related_article_id")+" and a.content_type='photo' and a.article_id=c.id and a.state=1 and c.published=1 ORDER BY a.id desc limit "+COMMENT_COUNT;
				//					System.out.println("rselectQuery->"+rselectQuery);
									cpstmt = cnr.prepareStatement(cQuery);
									crs = cpstmt.executeQuery();
									commentcount = 0;
									crs.last();
									commentcount=crs.getRow();
									//System.out.println("commentcount->"+commentcount);
									crs.beforeFirst();
									while(crs.next()){
											commentTagsComplete.append("<comment>");
											if(crs.getString("comment")!=null && !crs.getString("comment").equals("null")) {
												commentTagsComplete.append("<commenttext><![CDATA["+crs.getString("comment")+"]]></commenttext>");
											} else {
												commentTagsComplete.append("<commenttext></commenttext>");
											}
											if(crs.getString("fname")!=null && !crs.getString("fname").equals("null")) {
												commentTagsComplete.append("<name><![CDATA["+crs.getString("fname")+"]]></name>");
											} else {
												commentTagsComplete.append("<name></name>");
											}
											if(crs.getString("cdate")!=null && !crs.getString("cdate").equals("null")) {
												commentTagsComplete.append("<createddate><![CDATA["+crs.getString("cdate")+"]]></createddate>");
												commentTagsComplete.append("<createddatetime><![CDATA["+crs.getString("cdatetime")+"]]></createddatetime>");
											} else {
												commentTagsComplete.append("<createddate></createddate>");
												commentTagsComplete.append("<createddatetime></createddatetime>");
											}
											if(crs.getString("email")!=null && !crs.getString("email").equals("null") && crs.getInt("display_emailid")==1) {
												commentTagsComplete.append("<email><![CDATA["+crs.getString("email")+"]]></email>");
											} else {
												commentTagsComplete.append("<email></email>");
											}
											commentTagsComplete.append("</comment>");

									}
								} catch(Exception ex) {
									System.out.println("28 nokia-wp-it/stories/notification.jsp nokia-comment photos.jsp Data fetching Error-> "+ex.toString());
								} finally{
									if(cpstmt!=null)
										cpstmt.close();
									if(crs!=null)
										crs.close();
								}
								if(commentcount==0) {
									commentTagsComplete.append("<comment><commenttext></commenttext><name></name><createddate></createddate><createddatetime></createddatetime><email></email></comment>");
								}
								commentTagsComplete.append("</comments>");
								relatedPhotoSB.append(commentTagsComplete);
								//comment ends



							String xmlCreationPath = "";
							try {
							
							File sourceFile = null;
							String fileName="rphoto"+contentId;
							String relatedPhotoData="<?xml version='"+"1.0"+"' encoding='"+"utf-8"+"'?><Root>";
							relatedPhotoData=relatedPhotoData+relatedPhotoSB.toString();
							relatedPhotoData=relatedPhotoData+"</Root>";
							sourceFile = new File("");
							if (sourceFile.exists()) {
								File file = (new File(XMLPATH_STORY));
								fileName = fileName.replaceAll("%20", "");
								xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT; 
								FileOutputStream outLN = new FileOutputStream(xmlCreationPath);
								outLN.write(relatedPhotoData.getBytes());
								outLN.close();
								
							} else {
								xmlCreationPath = XMLPATH_STORY + fileName + FILE_EXT;
								FileOutputStream fos1 = new FileOutputStream(xmlCreationPath);
								fos1.write(relatedPhotoData.getBytes());
								fos1.flush();
								fos1.close();
								
							}
								fileGenerated=1;
								
							} catch (IOException ioe) {
								if(fileGenerated==0)
									System.out.println("29 nokia-wp-it/stories/notification.jsp nokia-stories-photos.jsp "+xmlCreationPath+" file creation Error");
							}
						//Related Photo XML Generating Code Ends
						} catch(Exception ee){
								System.out.println("30 nokia-wp-it/stories/notification.jsp nokia related_content.jsp photo fetching Error-> "+ee.toString());
						} finally {
							if(pstmt!=null)
								pstmt.close();
							if(rs!=null)
								rs.close();
						}

					}
					//Related Type PHOTO Till
				}
			} catch(Exception ee){
					System.out.println("31  nokia-wp-it/stories/notification.jsp nokia-stories-related_content.jsp Data fetching Error-> "+ee.toString());
			} finally {
				if(mainpstmt!=null)
					mainpstmt.close();
				if(mainrs!=null)
					mainrs.close();
			}
		}
	} catch(Exception ex)	{
		System.out.println("32 nokia-wp-it/stories/notification.jsp nokia-photos-related_content Connection Error -> "+ex.toString());
	} finally{
	try{
		if(cnr!=null)
		cnr.close();
		} catch(Exception ex)	{
		System.out.println("33  nokia-wp-it/stories/notification.jsp nokia-photos-related_content Connection Error -> "+ex.toString());
	}
	}
}
%>
