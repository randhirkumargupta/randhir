$(document).ready(function () {
    $(".tab-navigation > a").click(function () {
        $(".tab-navigation a").removeClass();
        $('.tab-wrapper').hide();
        $(this).addClass("selected");
        $("#" + $(this).attr("tab")).show();

    });
});
