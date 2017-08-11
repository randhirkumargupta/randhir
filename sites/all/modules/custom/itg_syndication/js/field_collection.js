(function($, Drupal)
{
	
	Drupal.ajax.prototype.commands.afterAjaxCallbackExample = function(ajax, response, status)
	{
		jQuery("#" +response.selectedValue.wrapper+" select").html(response.selectedValue.option_html);

		var frequency_val = jQuery("#" +response.selectedValue.wrapper).parent().prev().prev().find("input[type=radio]:checked").val();
		var number_of_tr = jQuery('.field-multiple-table tr').length;
		syndication_rules_show_filed_collection(number_of_tr);

		function syndication_rules_show_filed_collection(number_of_tr) {
			console.log("asd"+number_of_tr);
			for (i = 0; i <= number_of_tr; i++) {
				var field_syndication_frequency = jQuery('input[name="field_syndication_rule_details[und][' + i + '][field_syndication_frequency][und]"]:checked').val();
				
				if (field_syndication_frequency == "Weekly") {
					console.log(field_syndication_frequency);
					jQuery('[id^=\"edit-field-syndication-rule-details-und-' + i + '-field-syndication-set-day-und\"]').parent().parent().show();
				}

				if (field_syndication_frequency == "Monthly") {
					jQuery('[id^=\"edit-field-syndication-rule-details-und-' + i + '-field-syndication-set-day-month\"]').parent().parent().show();
				}

			}
		}


	};
}(jQuery, Drupal));


