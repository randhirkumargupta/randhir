jQuery(document).ready(function () {
    jQuery(".live-tv").click(function () {
        window.location.href = jQuery("#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3)").find("a").attr("href");
    });
});