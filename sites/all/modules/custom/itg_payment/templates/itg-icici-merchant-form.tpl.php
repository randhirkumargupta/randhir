<center><h1><?php echo t("Please do not refresh this page...") ?></h1></center>
<?php 
echo '<pre>';
print_r($param_list);
?>
<!--<form method="post" name="frm1" action="<?php print $form_action; ?>">
			<input type="text" name="timezone" value="<?php print $param_list['timezone']; ?>" />
			<input type="text" name="authenticateTransaction" value="<?php print $param_list['authenticateTransaction']; ?>" />
			<input size="50" type="text" name="txntype" value="<?php print $param_list['txntype']; ?>"  />
			<input size="50" type="text" name="txndatetime" value="<?php print $param_list['txndatetime']; ?>"  />
			<input size="50" type="text" name="hash" value="<?php print $param_list['hash']; ?>"  />
			<input size="50" type="text" name="currency" value="<?php print $param_list['currency']; ?>"  />
			<input size="50" type="text" name="mode" value="<?php print $param_list['mode']; ?>"  />
			<input size="50" type="text" name="storename" value="<?php print $param_list['storename']; ?>"  />
			<input size="50" type="text" name="chargetotal" value="1"  />
			<input size="50" type="text" name="sharedsecret" value="<?php print $param_list['sharedsecret']; ?>"  />
			<input type="text" name="responseSuccessURL" value="<?php print $param_list['responseSuccessURL']; ?>"  />
			<input type="text" name="responseFailURL" value="<?php print $param_list['responseFailURL']; ?>"  />
			<input type="text" name="hash_algorithm" value="<?php print $param_list['hash_algorithm']; ?>"/>
      <input type="submit" name="submit" value="Continue Payment">
</form>-->





<form method="post" name="frm1" action="https://test.ipg-online.com/connect/gateway/processing">
			<input type="text" name="timezone" value="IST" />
			<input type="text" name="authenticateTransaction" value="true" />
			<input size="50" type="text" name="txntype" value="sale"  />
			<input size="50" type="text" name="txndatetime" value="2017:02:21-16:04:32"  />
			<input size="50" type="text" name="hash" value="<?php print $param_list['hash']; ?>"  />
			<input size="50" type="text" name="currency" value="INR"  />
			<input size="50" type="text" name="mode" value="payonly"  />
			<input size="50" type="text" name="storename" value="3344000184"  />
			<input size="50" type="text" name="chargetotal" value="1"  />
			<input size="50" type="text" name="sharedsecret" value="asdf1234"  />
			<input type="text" name="responseSuccessURL" value="http://127.0.0.1:80/php_ipg/response_success.php"  />
			<input type="text" name="responseFailURL" value="http://127.0.0.1:80/php_ipg/response_fail.php"  />
			<input type="text" name="hash_algorithm" value="SHA1"/>
      <input type="submit" name="submit" value="Continue Payment">
</form>


<script type="text/javascript">
      //document.<?php //print ICICI_FORM_ID;?>.submit();
    </script>