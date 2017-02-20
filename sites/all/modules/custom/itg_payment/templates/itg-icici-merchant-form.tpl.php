<center><h1><?php echo t("Please do not refresh this page...") ?></h1></center>

<form method="post" action="<?php print ICICI_ACTION_URL ?>" name="<?php print ICICI_FORM_ID;?>">
    <table border="1">
        <tbody>
            <?php            
            foreach ($param_list as $name => $value) {
              echo '<input type="hidden" name="' . $name . '" value="' . $value['val'] . '" size="' . $value['size'] . '">';
            }
            ?>        
        </tbody>
    </table>
    <script type="text/javascript">
      document.<?php print ICICI_FORM_ID;?>.submit();
    </script>
</form>