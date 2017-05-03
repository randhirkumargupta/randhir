<?php
global $base_url;
header("Pragma: no-cache");
header("Cache-Control: no-cache");
header("Expires: 0");
echo t("Please wait we are redirecting payment gateway...");
?>
<div class="hide">
    <form id="amex-form" action="<?php echo $base_url; ?>/itg-payment-amex-order-form-action" method="post" accept-charset="UTF-8">
        <input type="hidden" name="Title" value = "PHP VPC 3 Party Transacion">
        <!-- get user input -->
        <table width="100%" align="center" border="0" cellpadding='0' cellspacing='0'>

            <tr class="shade">
                <td align="right"><strong><em>Virtual Payment Client URL:&nbsp;</em></strong></td>
                <td><input name="virtualPaymentClientURL" size="65" value="<?php echo VIRTUAL_PAYMENT_CLIENT_URL; ?>" maxlength="250"/></td>
            </tr>
            <tr><td colspan="2">&nbsp;<hr width="75%">&nbsp;</td></tr>
            <tr>
                <td align="right"><strong><em> VPC Version: </em></strong></td>
                <td><input name="vpc_Version" value="1" size="20" maxlength="8"/></td>
            </tr>
            <tr class="shade">
                <td align="right"><strong><em>Command Type: </em></strong></td>
                <td><input name="vpc_Command" value="pay" size="20" maxlength="16"/></td>
            </tr>
            <tr>
                <td align="right"><strong><em>Merchant AccessCode: </em></strong></td>
                <td><input name="vpc_AccessCode" value="<?php echo AMEX_MERCHANT_ACCESS_CODE; ?>" size="20" maxlength="8"/></td>
            </tr>
            <tr class="shade">
                <td align="right"><strong><em>Merchant Transaction Reference: </em></strong></td>
                <td><input name="vpc_MerchTxnRef" value="<?php echo $data['event_id']; ?>" size="20" maxlength="40"/></td>
            </tr>
            <tr>
                <td align="right"><strong><em>MerchantID: </em></strong></td>
                <td><input name="vpc_Merchant" value="<?php echo AMEX_MERCHANT_ID; ?>" size="20" maxlength="16"/></td>
            </tr>
            <tr class="shade">
                <td align="right"><strong><em>Transaction OrderInfo: </em></strong></td>
                <td><input name="vpc_OrderInfo" value="<?php echo $_SESSION['event_registration_payment']['amex_order_id']; ?>" size="20" maxlength="34"/></td>
            </tr>
            <tr>
                <td align="right"><strong><em>Purchase Amount: </em></strong></td>
                <?php
                // Amex amount is calculated by multiple by 100.
                $redeemed_amount = (int) $data['redeemed_payment'];
                $amex_amont = $redeemed_amount * 100;
                ?>
                <td><input name="vpc_Amount" value="<?php echo $amex_amont; ?>" maxlength="10"/></td>
            </tr>
            <tr class="shade">
                <td align="right"><strong><em>Receipt ReturnURL: </em></strong></td>
                <td><input name="vpc_ReturnURL" size="65" value="<?php echo VPC_RETURN_URL; ?>" maxlength="250"/></td>
            </tr>
            <tr>
                <td align="right"><strong><em>Payment Server Display Language Locale: </em></strong></td>
                <td>
                    <select name="vpc_Locale">
                        <option SELECTED>en</option>
                        <option>en</option>
                    </select>
                </td>
            </tr>
            <tr class="shade">
                <td align="right"><strong><em>Currency: </em></strong></td>
                <td>
                    <select name="vpc_Currency">
                        <option SELECTED>INR</option>
                    </select>
                </td>
            </tr>

            <tr>    <td colspan="2">&nbsp;</td></tr>
            <tr>
                <td>&nbsp;</td>
                <td><input type="submit" NAME="SubButL" value="Pay Now!"></td>
            </tr>
        </table>
    </form>
</div>
<script>
  document.getElementById("amex-form").submit();
</script>