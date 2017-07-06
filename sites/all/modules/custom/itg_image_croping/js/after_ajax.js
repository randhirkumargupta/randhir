(function($, Drupal)
{
  // Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
  Drupal.ajax.prototype.commands.image_croping_status = function(ajax, response, status)
  {
    // The value we passed in our Ajax callback function will be available inside the
    // response object. Since we defined it as selectedValue in our callback, it will be
    // available in response.selectedValue. Usually we would not use an alert() function
    // as we could use ajax_command_alert() to do it without having to define a custom
    // ajax command, but for the purpose of demonstration, we will use an alert() function
    // here:
    window.parent.location.reload(true);

  };
}(jQuery, Drupal));