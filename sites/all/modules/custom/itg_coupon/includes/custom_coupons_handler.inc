<?php

/**
 * A handler to provide a field that is will calculate difference between coupon_uses_limit - coupon_current_uses
.
 *
 * @ingroup views_field_handlers
 */
 class views_handler_custom_coupons_handler extends views_handler_field {
   function query() {
     // do nothing -- to override the parent query.
   }

   function option_definition() {
     $options = parent::option_definition();
     $options['alter']['contains']['alter_text'] = array('default' => TRUE);
     return $options;
   }

   function options_form(&$form, &$form_state) {
     parent::options_form($form, $form_state);

     unset($form['alter']['alter_text']);
     unset($form['alter']['text']['#dependency']);
     unset($form['alter']['text']['#process']);
   }

   function render($values) {
      return (int)$values->field_field_coupon_uses_limit[0]['raw']['value'] - (int) $values->field_field_coupon_current_uses[0]['raw']['value'] ;
   }
}