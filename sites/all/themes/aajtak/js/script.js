/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.my_custom_behavior = {
    attach: function(context, settings) {

      // Place your code here.
      $('.slider-container').slick({
        infinite: true,
        slidesToShow: 3,
        variableWidth: true,
        slidesToScroll: 1
      });
      $('.stack').each(function() {
        var stackId = $(this).attr('id');
        console.log('Stack ID = ' + stackId);
        if (stackId == 'stack-card') {
          var stack = new Stack(document.getElementById('stack-card'));
          document.querySelector('.button--accept[data-stack = stack-card]').addEventListener(clickeventtype, function() {
            stack.accept(buttonClickCallback.bind(this));
          });
          document.querySelector('.button--reject[data-stack = stack-card]').addEventListener(clickeventtype, function() {
            stack.reject(buttonClickCallback.bind(this));
          });
        }
        if (stackId == 'stack-card-0') {
          var stack_0 = new Stack(document.getElementById('stack-card-0'));
          document.querySelector('.button--accept[data-stack = stack-card-0]').addEventListener(clickeventtype, function() {
            stack_0.accept(buttonClickCallback.bind(this));
          });
          document.querySelector('.button--reject[data-stack = stack-card-0]').addEventListener(clickeventtype, function() {
            stack_0.reject(buttonClickCallback.bind(this));
          });
        }
        if (stackId == 'stack-card-1') {
          var stack_1 = new Stack(document.getElementById('stack-card-1'));
          document.querySelector('.button--accept[data-stack = stack-card-1]').addEventListener(clickeventtype, function() {
            stack_1.accept(buttonClickCallback.bind(this));
          });
          document.querySelector('.button--reject[data-stack = stack-card-1]').addEventListener(clickeventtype, function() {
            stack_1.reject(buttonClickCallback.bind(this));
          });
        }
        if (stackId == 'stack-card-2') {
          var stack_2 = new Stack(document.getElementById('stack-card-2'));
          document.querySelector('.button--accept[data-stack = stack-card-2]').addEventListener(clickeventtype, function() {
            stack_2.accept(buttonClickCallback.bind(this));
          });
          document.querySelector('.button--reject[data-stack = stack-card-2]').addEventListener(clickeventtype, function() {
            stack_2.reject(buttonClickCallback.bind(this));
          });
        }
      });
      
    }
  };


})(jQuery, Drupal, this, this.document);
