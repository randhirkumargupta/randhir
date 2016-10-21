<?php
/**
 * @file
 *   Refer a friend mail template.
 */
?> 

<!DOCTYPE html> 
<html xmlns:v="urn:schemas-microsoft-com:vml">
    <head>
        <title>India Today Account Activation Mail</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <table cellspacing="0" cellpadding="0" style="width: 100%; margin: 0 auto; font-family: Arial">
            <tr>
                <td style="padding: 10px 20px;">Dear <?php echo $data['name']; ?>,</td>
            </tr>
            <tr>
                <td style="padding: 10px 20px;">Please join this site.</td>
            </tr>
            <tr>
                <td style="padding: 10px 20px;"><?php echo $data['link']; ?></td>
            </tr>
            <tr>
                <td style="padding: 10px 20px;">Thanks,</td>
            </tr>
            <tr>
                <td style="padding: 0px 20px;">India Today Group</td>
            </tr>
        </table>
    </body>
</html>
