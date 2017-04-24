<html>
    <head>
        <title><?php echo $form_data['markup']['#markup']; ?></title>
    </head>
    <body>
    <center><h1><?php echo t("Please do not refresh this page...") ?></h1></center>
    <form method="post" action="<?php echo PAYTM_TXN_URL ?>" name="f1">
        <table border="1">
            <tbody>
                <?php
                foreach ($param_list as $name => $value) {
                  echo '<input type="hidden" name="' . $name . '" value="' . $value . '">';
                }
                ?>
            <input type="hidden" name="CHECKSUMHASH" value="<?php echo $check_sum ?>">
            </tbody>
        </table>
        <script type="text/javascript">
          document.f1.submit();
        </script>
    </form>
</body>
</html>