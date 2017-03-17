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
				<input type="text" name="timezone" value="<?php print $param_list['timezone']; ?>" />
			<input type="text" name="authenticateTransaction" value="<?php print $param_list['authenticateTransaction']; ?>" />
			<input size="50" type="text" name="txntype" value="<?php print $param_list['txntype']; ?>"  />
			<input size="50" type="text" name="txndatetime" value="<?php print $param_list['txndatetime']; ?>"  />
			<input size="50" type="text" name="hash" value="<?php print $param_list['hash']; ?>"  />
			<input size="50" type="text" name="currency" value="<?php print $param_list['currency']; ?>"  />
			<input size="50" type="text" name="mode" value="<?php print $param_list['mode']; ?>"  />
			<input size="50" type="text" name="storename" value="<?php print $param_list['storename']; ?>"  />
			<input size="50" type="text" name="chargetotal" value="<?php print $param_list['chargetotal']; ?>"  />
		<input size="50" type="text" name="sharedsecret" value="<?php print $param_list['sharedsecret']; ?>"  />
			<input type="text" name="responseSuccessURL" value="<?php print $param_list['responseSuccessURL']; ?>"  />
			<input type="text" name="responseFailURL" value="<?php print $param_list['responseFailURL']; ?>"  />
			<input type="text" name="hash_algorithm" value="<?php print $param_list['hash_algorithm']; ?>"/>
      <input type="submit" name="submit" value="Continue Payment">
</form>


<script type="text/javascript">
      //document.<?php //print ICICI_FORM_ID;?>.submit();
    </script>