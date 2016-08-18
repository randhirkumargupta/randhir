<?php

/**
 * @file views_customstyle_style_plugin.inc
 * Our handler.
 */

class views_customstyle_style_plugin extends views_plugin_style {

   /**
   * Add our option definitions.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['custom-class-firstlast'] = array('default' => 0);
    $options['custom-class-columncount'] = array('default' => 0);
		$options['custom-class-columncount-prefix'] = array('default' => 'listCol');
    return $options;
  }

  /**
   * Add our options to the form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
		
		$form['custom-class-firstlast'] = array(
			'#type' => 					'checkbox',
			'#title' =>					t('Add first/last classes'),
			'#default_value' =>	$this->options['custom-class-firstlast'],
		);
		
		$form['custom-class-columncount'] = array(
			'#type' => 					'select',
			'#title' =>					t('Add column count classes'),
			'#options' =>				array(
														0 => t('<Disabled>'), 
														2 => 2,
														3 => 3,
														4 => 4,
														5 => 5,
														6 => 6,
														7 => 7,
														8 => 8,
														9 => 9,
														10 => 10,
														11 => 11,
														12 => 12,
														13 => 13,
														14 => 14,
														15 => 15,
														16 => 16,
														17 => 17,
														18 => 18,
														19 => 19,
														20 => 20,
													),
			'#default_value' =>	$this->options['custom-class-columncount'],
		);
		
		$form['custom-class-columncount-prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Column count class prefix'),
      '#default_value' => $this->options['custom-class-columncount-prefix'],
      '#size' => 20,
		);
  }
} // end of class definition
