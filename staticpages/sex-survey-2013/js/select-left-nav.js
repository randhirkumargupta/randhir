$(document).ready(function () {
    $("#root .category").click(function () {
        var childid = "#" + $(this).attr("childid");
        if ($(childid).css("display") == "none") { $(childid).css("display", "block"); }
        else { $(childid).css("display", "none"); }
        if ($(this).hasClass("cat_close")) { $(this).removeClass("cat_close").addClass("cat_open"); }
        else { $(this).removeClass("cat_open").addClass("cat_close"); }
    });

    $("#root ul").each(function () { $(this).css("display", "none"); });

    var str = window.location.pathname;
    var v1 = str.split("/");
    var pagename = v1[parseInt(v1.length) - 1]
    var rootid;
    var childid;

    if (pagename == "s1-awakening-dating-ever-dated.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    if (pagename == "s1-awakening-dating-age.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    if (pagename == "s1-awakening-dating-number-of-partners.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    if (pagename == "s1-awakening-dating-criteria.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    if (pagename == "s1-awakening-dating-online-dating.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    if (pagename == "s1-awakening-dating-blind-date.shtml") { rootid = "#c_1"; childid = "#c_11"; }

    if (pagename == "s1-awakening-kissing-ever-kissed.shtml") { rootid = "#c_1"; childid = "#c_12"; }
    if (pagename == "s1-awakening-kissing-first-kiss.shtml") { rootid = "#c_1"; childid = "#c_12"; }
    if (pagename == "s1-awakening-kissing-forms-of-kissing.shtml") { rootid = "#c_1"; childid = "#c_12"; }
    if (pagename == "s1-awakening-kissing-emotions-attached-with-kissing.shtml") { rootid = "#c_1"; childid = "#c_12"; }

    if (pagename == "s1-awakening-love-eever-fallen-in-love.shtml") { rootid = "#c_1"; childid = "#c_13"; }
    if (pagename == "s1-awakening-love-first-love.shtml") { rootid = "#c_1"; childid = "#c_13"; }
    if (pagename == "s1-awakening-love-impressive-qualities.shtml") { rootid = "#c_1"; childid = "#c_13"; }
    if (pagename == "s1-awakening-love-sex-in-relationship.shtml") { rootid = "#c_1"; childid = "#c_13"; }

    if (pagename == "s1-awakening-masturbation-ever-masturbated.shtml") { rootid = "#c_1"; childid = "#c_14"; }
    if (pagename == "s1-awakening-masturbation-masturbation-history.shtml") { rootid = "#c_1"; childid = "#c_14"; }
    if (pagename == "s1-awakening-masturbation-frequency.shtml") { rootid = "#c_1"; childid = "#c_14"; }

    if (pagename == "s1-awakening-porn-interest-in-porn.shtml") { rootid = "#c_1"; childid = "#c_15"; }
    if (pagename == "s1-awakening-porn-frequency.shtml") { rootid = "#c_1"; childid = "#c_15"; }
    if (pagename == "s1-awakening-porn-you-watch-porn-with.shtml") { rootid = "#c_1"; childid = "#c_15"; }
    if (pagename == "s1-awakening-porn-porn-and-sex.shtml") { rootid = "#c_1"; childid = "#c_15"; }

    if (pagename == "s1-awakening-sex-family-matters.shtml") { rootid = "#c_1"; childid = "#c_16"; }
    if (pagename == "s1-awakening-sex-first-brush-with-sex.shtml") { rootid = "#c_1"; childid = "#c_16"; }
    if (pagename == "s1-awakening-sex-age.shtml") { rootid = "#c_1"; childid = "#c_16"; }




    if (pagename == "s2-discovery-sexual-history-importance-of-sex.shtml") { rootid = "#c_2"; childid = "#c_21"; }
    if (pagename == "s2-discovery-sexual-history-first-sexual-experience.shtml") { rootid = "#c_2"; childid = "#c_21"; }
    if (pagename == "s2-discovery-sexual-history-first-sexual-partner.shtml") { rootid = "#c_2"; childid = "#c_21"; }
    if (pagename == "s2-discovery-sexual-history-sexually-active.shtml") { rootid = "#c_2"; childid = "#c_21"; }

    if (pagename == "s2-discovery-sexual-habit-sexual-orientation.shtml") { rootid = "#c_2"; childid = "#c_22"; }
    if (pagename == "s2-discovery-sexual-habit-sexually-active.shtml") { rootid = "#c_2"; childid = "#c_22"; }
    if (pagename == "s2-discovery-sexual-habit-favorite-position.shtml") { rootid = "#c_2"; childid = "#c_22"; }
    if (pagename == "s2-discovery-sexual-habit-sexual-turn-ons.shtml") { rootid = "#c_2"; childid = "#c_22"; }

    if (pagename == "s2-discovery-present-satisfaction-level-sexual-satisfaction.shtml") { rootid = "#c_2"; childid = "#c_23"; }
    if (pagename == "s2-discovery-present-satisfaction-level-equal-sexual-participation.shtml") { rootid = "#c_2"; childid = "#c_23"; }
    if (pagename == "s2-discovery-present-satisfaction-level-ideal-sex-partner.shtml") { rootid = "#c_2"; childid = "#c_23"; }
    if (pagename == "s2-discovery-present-satisfaction-level-the-big-o.shtml") { rootid = "#c_2"; childid = "#c_23"; }

    if (pagename == "s2-discovery-sex-procreation-vs-recreation-sex-for-reproduction.shtml") { rootid = "#c_2"; childid = "#c_24"; }

    if (pagename == "s2-discovery-sex-fantasy-sexual-fantasies.shtml") { rootid = "#c_2"; childid = "#c_25"; }
    if (pagename == "s2-discovery-sex-fantasy-favorite-fantasies.shtml") { rootid = "#c_2"; childid = "#c_25"; }
    if (pagename == "s2-discovery-sex-fantasy-experience-of-sexual-fantasies.shtml") { rootid = "#c_2"; childid = "#c_25"; }
    if (pagename == "s2-discovery-sex-fantasy-sexual-fantasies-and-partner.shtml") { rootid = "#c_2"; childid = "#c_25"; }

    if (pagename == "s2-discovery-sexual-experiments-foreplay-before-sex.shtml") { rootid = "#c_2"; childid = "#c_26"; }
    if (pagename == "s2-discovery-sexual-experiments-role-playing.shtml") { rootid = "#c_2"; childid = "#c_26"; }
    if (pagename == "s2-discovery-sexual-experiments-sex-games.shtml") { rootid = "#c_2"; childid = "#c_26"; }
    if (pagename == "s2-discovery-sexual-experiments-sex-enhancers.shtml") { rootid = "#c_2"; childid = "#c_26"; }

    if (pagename == "s2-discovery-innovative-sexual-practices-new-postures.shtml") { rootid = "#c_2"; childid = "#c_27"; }
    if (pagename == "s2-discovery-innovative-sexual-practices-anal-sex.shtml") { rootid = "#c_2"; childid = "#c_27"; }
    if (pagename == "s2-discovery-innovative-sexual-practices-oral-pleasure.shtml") { rootid = "#c_2"; childid = "#c_27"; }






    if (pagename == "s3-sex-sex-and-marriage-virgin-or-sexually-experienced-partner.shtml") { rootid = "#c_3"; childid = "#c_31"; }
    if (pagename == "s3-sex-sex-and-marriage-marriage-and-virginity.shtml") { rootid = "#c_3"; childid = "#c_31"; }
    if (pagename == "s3-sex-sex-and-marriage-virgin-partner.shtml") { rootid = "#c_3"; childid = "#c_31"; }

    if (pagename == "s3-sex-contraceptives-morning-pills.shtml") { rootid = "#c_3"; childid = "#c_32"; }

    if (pagename == "s3-sex-sex-beyond-marriage-extra-marital-sex.shtml") { rootid = "#c_3"; childid = "#c_33"; }
    if (pagename == "s3-sex-sex-beyond-marriage-your-opinion.shtml") { rootid = "#c_3"; childid = "#c_33"; }

    if (pagename == "s3-sex-adultary-consensual-affairs.shtml") { rootid = "#c_3"; childid = "#c_34"; }
    if (pagename == "s3-sex-adultary-wife-swapping.shtml") { rootid = "#c_3"; childid = "#c_34"; }

    if (pagename == "s3-sex-voyeurism-involvement-in-voyeurism.shtml") { rootid = "#c_3"; childid = "#c_35"; }
    if (pagename == "s3-sex-voyeurism-kind-of-voyeurism.shtml") { rootid = "#c_3"; childid = "#c_35"; }

    if (pagename == "s3-sex-homosexuality-bisexuality-homosexuality-and-you.shtml") { rootid = "#c_3"; childid = "#c_36"; }
    if (pagename == "s3-sex-homosexuality-bisexuality.shtml") { rootid = "#c_3"; childid = "#c_36"; }

    if (pagename == "s3-sex-incest-sex-in-family-incest-relationships.shtml") { rootid = "#c_3"; childid = "#c_37"; }
    if (pagename == "s3-sex-incest-sex-in-family-involvement-in-incest-relationships.shtml") { rootid = "#c_3"; childid = "#c_37"; }



    if (pagename == "s4-family-sex-education-relationship-with-children.shtml") { rootid = "#c_4"; childid = "#c_41"; }
    if (pagename == "s4-family-sex-education-safe-sex.shtml") { rootid = "#c_4"; childid = "#c_41"; }

    if (pagename == "s4-family-other-matters-guidance-on-sexual-issues.shtml") { rootid = "#c_4"; childid = "#c_42"; }
    if (pagename == "s4-family-other-matters-sex-therapist-for-better-sex-life.shtml") { rootid = "#c_4"; childid = "#c_42"; }
    if (pagename == "s4-family-other-matters-consultaion-with-partner.shtml") { rootid = "#c_4"; childid = "#c_42"; }
    if (pagename == "" || pagename == "index.shtml") { rootid = "#c_1"; childid = "#c_11"; }
    //alert(pagename);



    $(rootid).each(function () {
        $(this).css("display", "block");
        $(this).siblings('a').removeClass("cat_close").addClass("cat_open");
    });
    $(childid).each(function () {
        $(this).css("display", "block");
        $(this).siblings('a').removeClass("cat_close").addClass("cat_open");
    });


});