<?php

/*
 * Returns the string as user roles and thier permissions
 */

function itg_user_role_and_permissions() {

  $rol_per = '<div class="token-table">
        <div class="itgadmin-popup-wrapper" id="mail-templates-token" style="display:none">
          <div class="itgadmin-popup">
            <span class="close-itgadmin-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
            <h2>' . t('Permissions According to Roles') . '</h2>
            <div class="mail-table">
        		<table class="views-table">
            <thead>
                <th>' . t('Permission Name/Roles') . '</th>
                <th>' . t('Author /Guest') . '</th>
                <th>' . t('Intern') . '</th>
                <th>' . t('Subeditor/Sr. Sub') . '</th>
                <th>' . t('Copy Editor') . '</th>
                <th>' . t('Section Editor / Anchor') . '</th>
                <th>' . t('Editor') . '</th>
                <th>' . t('UGC Moderator') . '</th>
                <th>' . t('Social Media') . '</th>
                <th>' . t('As Expert') . '</th>
                <th>' . t('SEO') . '</th>
                <th>' . t('Correspondent') . '</th>
                <th>' . t('Coordinator') . '</th>
                <th>' . t('Photo Coordinator') . '</th>
                <th>' . t('Photo Head') . '</th>
                <th>' . t('Design Head') . '</th>
                <th>' . t('Copy Desk Designer') . '</th>
                <th>' . t('Photographer') . '</th>
                <th>' . t('Marketing Manager') . '</th>
            </thead>
            <tbody>
                <tr>
                    <th>' . t('File content') . '</th>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Reviewer approve/reject') . '</th> 
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Un publish') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Assign content') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Section/category creation') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('UGC Moderation') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('User creation') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Poll Creation') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Question Answer & Post Reply') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Content Creation for VAS') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Client, Service Creation and association for VAS') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Newsletter creation') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td>' . t('No') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Submit Idea for Print Team') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Review Idea Approve /Reject') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Add member with approved idea') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Mark Task Completion') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Meta Description, Meta Keyword, SEF URL for all Content Type') . '</th>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Social Media Add/Edit for all Content Type') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td></td>
                    <td></td>
                    <td>' . t('Yes') . '</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <th>' . t('Complete Loyalty Section and Poduct creation for Redemption') . '</th>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td></td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('No') . '</td>
                    <td>' . t('Yes') . '</td>
                </tr>
            </tbody>

            </table>
          </div>
        </div>
      </div>';
  return $rol_per;

}
