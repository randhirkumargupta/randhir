<html>
    <body>
    <center><h1><?php echo t("Please do not refresh this page...") ?></h1></center>
    <div class="hide" style="display:none;">
      <form method="post" name="frm1" id="myForm" action="https://test.ipg-online.com/connect/gateway/processing">
          <input type="hidden" name="timezone" value="<?php print $param_list['timezone']; ?>" />
          <input type="hidden" name="authenticateTransaction" value="<?php print $param_list['authenticateTransaction']; ?>" />
          <input size="50" type="hidden" name="txntype" value="<?php print $param_list['txntype']; ?>"  />
          <input size="50" type="hidden" name="txndatetime" value="<?php print $param_list['txndatetime']; ?>"  />
          <input size="50" type="hidden" name="hash" value="<?php print $param_list['hash']; ?>"  />
          <input size="50" type="hidden" name="currency" value="<?php print $param_list['currency']; ?>"  />
          <input size="50" type="hidden" name="mode" value="<?php print $param_list['mode']; ?>"  />
          <input size="50" type="hidden" name="storename" value="<?php print $param_list['storename']; ?>"  />
          <input size="50" type="hidden" name="chargetotal" value="<?php print $param_list['chargetotal']; ?>"  />
          <input size="50" type="hidden" name="sharedsecret" value="<?php print $param_list['sharedsecret']; ?>"  />
          
          <input size="50" type="hidden" name="order_id" value="<?php print $param_list['order_id']; ?>"  />
          
          <input type="text" name="responseSuccessURL" value="<?php print $param_list['responseSuccessURL']; ?>"  />
          <input type="text" name="responseFailURL" value="<?php print $param_list['responseFailURL']; ?>"  />
          <input type="text" name="hash_algorithm" value="<?php print $param_list['hash_algorithm']; ?>"/>
          <input type="submit" name="submit_button" value="Continue Payment">
      </form>
    </div>
    <script>
      myFunction();
      function myFunction() {
          document.getElementById("myForm").submit();
      }
    </script>
</body>
</html>