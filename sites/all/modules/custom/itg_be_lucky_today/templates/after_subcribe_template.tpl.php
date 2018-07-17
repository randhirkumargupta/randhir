<script language="javascript">
    function callNow()
    {
        document.frm.method = "POST";
        document.frm.action = "<?php print $data->payment_url; ?>"
        document.frm.submit();
    }
    setTimeout(function () {
        callNow();
    }, 100);
</script>
<div onLoad="callNow()">
    <form name="frm" method="post">
        <input type="hidden" name="name" value="<?php echo $data->name; ?>">
        <input type="hidden" name="source" value="<?php echo $data->source; ?>">
        <input type="hidden" name="user_id" value="<?php echo $data->user_id; ?>">
        <input type="hidden" name="gender" value="<?php echo $data->gender; ?>">
        <input type="hidden" name="age" value="<?php echo $data->age; ?>">
        <input type="hidden" name="email" value="<?php echo $data->email; ?>">
        <input type="hidden" name="address" value="<?php echo $data->address; ?>">
        <input type="hidden" name="city" value="<?php echo $data->city; ?>">
        <input type="hidden" name="state" value="<?php echo $data->state; ?>">
        <input type="hidden" name="zip" value="<?php echo $data->studled; ?>">
        <input type="hidden" name="mobile" value="<?php echo $data->mobile; ?>">
        <input type="hidden" name="magazine" value="<?php echo $data->magazine2; ?>">
        <input type="hidden" name="payGStype" value="<?php echo $data->payment_method; ?>">
        <input type="hidden" name="key" value="<?php echo $data->key; ?>">
        <INPUT TYPE="hidden" NAME="product_id" value="<?php echo $data->product_id; ?>">
    </form>
</div>