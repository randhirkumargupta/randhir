<?php

/*
 * @param $token_table is a string that returns the table for tokens
 */

function itg_mail_templates_tokenstable() {
  
  $token_table = '<div class="token-table">
        <div class="itgadmin-popup-wrapper" id="mail-templates-token" style="display:none">
          <div class="itgadmin-popup">
            <span class="close-itgadmin-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
            <h2>ITG mail templates token</h2>
            <div class="mail-table">
        		<table class="views-table">
            <thead>
              <th> Token name</th>
              <th> Token value</th>
              <th> Token description</th>
            </thead>
            <tbody>
      			  <tr>
                <td colspan="3"><b>Tokens For Ask an Expert</b></td>
              </tr>
              <tr>
                <td>ITG Ask an Expert City</td>
                <td>[itg_mail_token:itg_expert_city]</td>
                <td>A token that will be used for ITG Ask an Expert City.</td>
              </tr>
              <tr>
                <td>ITG Ask an Expert Email</td>
                <td>[itg_mail_token:itg_expert_email]</td>
                <td>A token that will be used for ITG ITG Ask an Expert Email.</td>
              </tr>
              <tr>
                <td>ITG Ask an Expert Name</td>
                <td>[itg_mail_token:itg_expert_name]</td>
                <td>A token that will be used for ITG Ask an Expert Name.</td>
              </tr>
              <tr>
                <td>ITG Ask an Expert Question</td>
                <td>[itg_mail_token:itg_expert_question]</td>
                <td>A token that will be used for ITG Ask an Expert Question.</td>
              </tr>
              <tr>
                <td>ITG Ask an Expert State</td>
                <td>[itg_mail_token:itg_expert_state]</td>
                <td>A token that will be used for ITG Ask an Expert State.</td>
              </tr>
              <tr>
                <td>ITG Content Author</td>
                <td>[itg_mail_token:itg_author]</td>
                <td>A token that will be used for ITG Content Author in Mail Body.</td>
              </tr>
              <tr>
                <td>ITG Logged In User Name</td>
                <td>[itg_mail_token:itg_loggedin_user]</td>
                <td>A token that will be used for ITG Logged In User Name.</td>
              </tr>
              <tr>
                <td colspan="3"><b>Tokens For Loyalty Points</b></td>
              </tr>
              <tr>
                <td>ITG Loyalty Points</td>
                <td>[itg_mail_token:itg_loyalty_points]</td>
                <td>A token that will be used for ITG Loyalty Expiry.</td>
              </tr>
              <tr>
                <td>ITG Loyalty User</td>
                <td>[itg_mail_token:itg_loyalty_user]</td>
                <td>A token that will be used for ITG Loyalty User Name.</td>
              </tr>
              <tr>
                <td>ITG Loyalty and Reward Expiry</td>
                <td>[itg_mail_token:itg_loyalty_expiry]</td>
                <td>A token that will be used for ITG Loyalty and Reward Expiry.</td>
              </tr>
              <tr>
                <td colspan="3"><b>Tokens For Node</b></td>
              </tr>
              <tr>
                <td>ITG NODE TYPE</td>
                <td>[itg_mail_token:itg_node_type]</td>
                <td>A token that will be used for ITG Node Type.</td>
              </tr>
              <tr>
                <td>ITG Node Title</td>
                <td>[itg_mail_token:itg_node_title]    </td>
                <td>A token that will be used for ITG Content Title in Mail Body.</td>
              </tr>
              <tr>
                <td>ITG Node Nid</td>
                <td>[itg_mail_token:itg_node_nid]    </td>
                <td>A token that will be used for ITG Content Nid in Mail Body.</td>
              </tr>
              <tr>
                <td>ITG Node Title With Link</td>
                <td>[itg_mail_token:itg_node_title_link]</td>
                <td>A token that will be used for ITG Node Title With Link.</td>
              </tr>
              <tr>
                <td>ITG Task/Idea</td>
                <td>[itg_mail_token:itg_node_body]</td>
                <td>A token that will be used for ITG Task/Idea.</td>
              </tr>
              <tr>
                <td colspan="3"><b>Tokens For Product</b></td>
              </tr>
              <tr>
                <td>ITG Product/Inventry Count</td>
                <td>[itg_mail_token:itg_product_count]</td>
                <td>A token that will be used for ITG Product/Inventry Count.</td>
              </tr>
              <tr>
                <td>ITG Product Code</td>
                <td>[itg_mail_token:itg_product_code]</td>
                <td>A token that will be used for ITG Product Code.</td>
              </tr>
              <tr>
                <td>ITG Product Name</td>
                <td>[itg_mail_token:itg_product_name]</td>
                <td>A token that will be used for ITG Product Name.</td>
              </tr>
              
              <tr>
                <td colspan="3"><b>Tokens For User/Site</b></td>
              </tr>
              <tr>
                <td>ITG User First Name</td>
                <td>[itg_mail_token:itg_account_user_fname]</td>
                <td>A token that will be used for ITG Account User First Name.</td>
              </tr>
              <tr>
                <td>ITG User Last Name</td>
                <td>[itg_mail_token:itg_account_user_lname]</td>
                <td>A token that will be used for ITG Account User First Name.</td>
              </tr>
              <tr>
                <td>ITG Account Activation</td>
                <td>[itg_mail_token:itg_account_activation_link]</td>
                <td>A token that will be used for ITG Account Activation.</td>
              </tr>
              <tr>
                <td>ITG Site Name</td>
                <td>[itg_mail_token:itg_site_name]</td>
                <td>A token that will be used for ITG Site Name.</td>
              </tr>
              <tr>
                <td colspan="3"><b>Tokens For Quiz Completion</b></td>
              </tr>
              <tr>
                <td>ITG Quiz Winner List</td>
                <td>[itg_mail_token:itg_quiz_winner_list]</td>
                <td>A token that will be used for ITG Quiz Winner List.</td>
              </tr>
              <tr>
                <td colspan="3"><b>Tokens For Task/Idea</b></td>
              </tr>
              <tr>
                <td>ITG Task Assignee</td>
                <td>[itg_mail_token:itg_task_assignee]</td>
                <td>A token that will be used for ITG Task Assignee</td>
              </tr>
              <tr>
                <td>ITG Task Assigner</td>
                <td>[itg_mail_token:itg_task_assigner]</td>
                <td>A token that will be used for ITG Task Assigner</td>
              </tr>
              <tr>
                <td>ITG Task Comment</td>
                <td>[itg_mail_token:itg_task_comment]</td>
                <td>A token that will be used for ITG Task Comment</td>
              </tr>
              <tr>
                <td>ITG Task Date/Time</td>
                <td>[itg_mail_token:itg_task_date_time]</td>
                <td>A token that will be used for ITG Task Expiry Date Time</td>
              </tr>
            </tbody>
            </table>
          </div>
        </div>
      </div>';
  return $token_table;
}