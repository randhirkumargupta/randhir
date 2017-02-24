
jQuery(document).ready(function($) {
    $('#list').click(function(event){event.preventDefault();$('#products .item').addClass('list-group-item');});
    $('#grid').click(function(event){event.preventDefault();$('#products .item').removeClass('list-group-item');$('#products .item').addClass('grid-group-item');});

	$("#list").click(function(){
	 $('#grid').removeClass("active_btn");
	 $(this).addClass("active_btn");

		});

		$("#grid").click(function(){
	 $('#list').removeClass("active_btn");
	 $(this).addClass("active_btn");

		});

});

jQuery(document).ready(function($){
    var click = true;
    $(document).on('click','div.dropdown',function(e){
        e.preventDefault();
        if(click){
          //$('.option').stop().slideUp(300);
            $(this).next('.option').stop().slideDown(300);
            click = false;
        }else{
          //$('.option').stop().slideDown(300);
            $(this).next('.option').stop().slideUp(300);
            click = true;
        }

    });

    $(document).on('click','.option li',function(e){
        e.preventDefault();
        var option_value = $(this).text();


        $(this).parent('ul').prev('.dropdown').children('b').text(option_value);

        //console.log("ASDASDASD" +  $($(this).parent('ul')).prev('.dropdown b').text(option_value))
      // $('.dropdown b').text(option_value);
        $('.option').slideUp(300);
        click = true;
    });
});
