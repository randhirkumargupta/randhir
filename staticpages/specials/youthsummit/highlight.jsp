<?php
require_once ("../configuration.php");
global $mosConfig_live_site,$database,$mosConfig_absolute_path,$mosConfig_cachepath;
require_once ("nencache/nen.cache.php");
$path = $mosConfig_cachepath.'/'; // We set cache path ! Do not forget '/'
$cache_adv = new nencache;
//File name is 'cache_simple' and life is 10 seconds
if ($cache_adv -> start ('conclave2011_highlight',3600,$path)) {
$mosConfig_db = 'itoday';
$mosConfig_dbprefix = 'jos_';
$mosConfig_smtphost = 'itdbslave';
$mosConfig_user = 'itoday_read'; 
$mosConfig_password = '!+0_re@d@111';
mysql_connect($mosConfig_smtphost,$mosConfig_user,$mosConfig_password) or die("Unable to connect to server");
mysql_select_db($mosConfig_db) or die("Unable to connect to database");

$highlights_sql = "select c.sef_url, c.id, c.title, c.created, c.fulltext from jos_content as c where c.id='132670'";
$highlights_res=@mysql_query($highlights_sql);
$highlights_result=@mysql_fetch_assoc($highlights_res);

$str = $highlights_result['fulltext'];
$head = explode("#",$str);
$count = count($head);
$j =$count-1;
for($i=0; $i<$count;$i++)
{
	$main[] = explode("Highlights ".$j.":",$head[$i]);
	$main2[] = $main[$i][1];
	$j--;	
}
$len = count($main2)-1;
unset($main2[$len]);
$main2= array_reverse($main2);
$rating_id=8888888;
for($i=0;$i<count($main2);$i++)
{
	$arr[$rating_id] = $main2[$i];
	$rating_id++;
}
//echo "<pre>";print_r($arr);echo "</pre>";
?>
<html xmlns="http://www.w3.org/1999/xhtml">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<meta http-equiv="refresh" content="30">
<style type="text/css">  
body {margin:0; padding:0;}
#divContent1 {font:normal 12px arial; color:#6a6a6a; line-height:18px; width:190px; float:left; overflow:hidden;}
#divContent1 a {font:normal 12px arial; color:#6a6a6a; line-height:18px; text-decoration:none;}
#divContent1 a:hover {font:normal 12px arial; color:#6a6a6a; line-height:18px; text-decoration:underline;}
#divContent1 ul{list-style:none; float:left; margin:0; padding:0;}
#divContent1 ul li { list-style:none; color:#6a6a6a; font:normal 12px arial; margin:0px; padding:0px 2px 2px 0px;line-height:18px;}
.budghiglit {width:188px; border-bottom:1px solid #e2e2e2; padding-top:3px; padding-bottom:5px; text-align:right;}
</style>
</head>
<body>
    <div id="divContent1">
        <ul>
            <?php 
            krsort($arr);
            //echo "<pre>";print_r($arr);echo "</pre>";
            foreach($arr as $key=>$val)
            {
            ?> 
            <li>
                <?php echo $val;?>   
                <div class="budghiglit">
                    <span class="rightdiv">
                        <a href="http://twitter.com/share" class="twitter-share-button" data-url="http://conclave.intoday.in" data-counturl="http://intoday.in" data-text="<?php echo $val;?> #ITConclave" data-count="none" data-via="" target="_blank"></a>
                    </span>
                </div>
            </li>
            <?php } ?>
         </ul>
    </div>
    <script type="text/javascript" src="http://platform.twitter.com/widgets.js"></script>
</body>
</html>
<? $cache_adv -> build ($path)/*Put Path here too*/;}  ?>

