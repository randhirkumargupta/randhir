/*
 Election constituency js 
 */

function getConstituencyData(jsonUrl, jsonKey) {
    if (jsonUrl === undefined || jsonKey === undefined) {
        return;
    }

    jQuery.ajax({
        type: "GET",
        url: jsonUrl,
        cache: true,
        crossDomain: true,
        success: function (data) {
            renderConstituencyBlocks(data[jsonKey], jsonKey);
        },
        error: function (error) {
            console.log(error, 'Constituency json error');
        }
    });
}
jQuery(document).ready(function () {
    if (Drupal.settings.json_url !== undefined && Drupal.settings.constituency !== undefined) {
        var refresh_time = 5000;
        if(Drupal.settings.refresh_time !== undefined){
                refresh_time = Drupal.settings.refresh_time;
        }
        setInterval(function () {
            getConstituencyData(Drupal.settings.json_url, Drupal.settings.constituency);
        }, refresh_time);
    }
});

function renderConstituencyBlocks(data, jsonKey) {
    if (data.candidate === undefined || data.candidate.length <= 0)
        return;

    var isWon = false;
    var isLeading = false;
    var isSeating = false;
    var wonCondidate = undefined;
    var seatingCondidate = undefined;
    var otherCondidates = [];
    jQuery.each(data.candidate, function (key, value) {
        if (value.win_loss !== undefined && value.win_loss == "WON" && !isWon && value.candidate_type == 'contesting') {
            isWon = true;
            wonCondidate = value;
        } else if (value.candidate_type == "seating") {
            isSeating = true;
            seatingCondidate = value;
        }
        if (value.candidate_type == 'contesting') {
            otherCondidates.push(value);
        }
        if (value.win_loss !== undefined && value.win_loss == "LEADING" && value.candidate_type == 'contesting') {
            isLeading = true;
        }
    });
    if (isWon) {
        //otherCondidates.push(seatingCondidate);
        showWonConstituencyCandidatesHTML(wonCondidate, data, jsonKey);
    }
    if (!isWon && isSeating) {
        showWonConstituencyCandidatesHTML(seatingCondidate, data, jsonKey);
    }
    if (otherCondidates.length > 0) {
        showOthersConstituencyCandidatesHTML(otherCondidates, data, isWon, isLeading);
    }

}

function showWonConstituencyCandidatesHTML(data, consData, constituencyName) {
    if (data.image !== undefined) {
        jQuery("#constituency-top-chunk #candidates #candidates-image img").attr('src', data.image);
    } else {
        jQuery("#constituency-top-chunk #candidates #candidates-image img").hide()
    }
    jQuery("#constituency-top-chunk #candidates #candidates-image div").html((data.candidate !== undefined ? data.candidate : ''));

    var html = "";
    html += "<tr><td>Party</td><td>" + (data.party !== undefined ? data.party : '') + "</td></tr>";
    html += "<tr><td>Gender</td><td>" + (data.gender !== undefined ? data.gender : '') + "</td></tr>";
    html += "<tr><td>Age</td><td>" + (data.age !== undefined ? data.age : '') + "</td></tr>";
    html += "<tr><td>Education Qualification</td><td>" + (data.qualification !== undefined ? data.qualification : '') + "</td></tr>";
    html += "<tr><td>Profession</td><td>" + (data.profession !== undefined ? data.profession : '') + "</td></tr>";
    html += "<tr><td>Marital status</td><td>" + (data.marital_status !== undefined ? data.marital_status : '') + "</td></tr>";
    html += "<tr><td>Criminal Cases</td><td>" + (data.criminal_cases !== undefined ? data.criminal_cases : '') + "</td></tr>";
    html += "<tr><td>Assets</td><td>" + (data.assets !== undefined ? data.assets : '') + "</td></tr>";
    html += "<tr><td>Movable Assets</td><td>" + (data.moveable_assets !== undefined ? data.moveable_assets : '') + "</td></tr>";
    html += "<tr><td>Immovable Assets</td><td>" + (data.immovable_assets !== undefined ? data.immovable_assets : '') + "</td></tr>";
    html += "<tr><td>Income</td><td>" + (data.income !== undefined ? data.income : '') + "</td></tr>";
    jQuery("#constituency-top-chunk #candidates table tbody").html(html);
    if (consData.lbl_candidates !== undefined) {
        jQuery("#constituency-top-chunk #candidates .heading").html(consData.lbl_candidates);
    } else {
        jQuery("#constituency-top-chunk #candidates .heading").html('Candidates');
    }
    
    if (constituencyName !== undefined){
        var constituencyName_t = constituencyName.split('-');
        var constituencyNameLab = constituencyName_t.join(" ");
        constituencyNameLab = constituencyNameLab.toLowerCase().replace(/\b[a-z]/g, function(letter) {
                return letter.toUpperCase();
            });
    }else {
        var constituencyNameLab = '';
    }
    
    var mocHTML = "";
    mocHTML += "<tr><td>AC name</td><td>" + (constituencyNameLab !== undefined ? constituencyNameLab : '') + "</td></tr>";
    mocHTML += "<tr><td>AC No</td><td>" + (consData.id !== undefined ? consData.id : '') + "</td></tr>";
    mocHTML += "<tr><td>District</td><td>" + (consData.district !== undefined ? consData.district : '') + "</td></tr>";
    jQuery("#constituency-top-chunk #map-of-constituency table tbody").html(mocHTML);
    if (consData.svg !== undefined) {
        jQuery("#constituency-top-chunk #map-of-constituency #candidates-svg").html(consData.svg);
    }
    if (consData.lbl_mapofconstituency !== undefined) {
        jQuery("#constituency-top-chunk #map-of-constituency .heading").html(consData.lbl_mapofconstituency);
    } else {
        jQuery("#constituency-top-chunk #map-of-constituency .heading").html('Map of constituency');
    }
}

function showOthersConstituencyCandidatesHTML(data, consData, isWon, isLeading) {
    var html = "";
    jQuery.each(data, function (key, value) {
        if (value !== undefined) {
            if (consData.live !== undefined && consData.live != "1") {
               html += "<tr><td data-column='"+ (consData.label.candidate_name !== undefined ? consData.label.candidate_name : 'CANDIDATE NAME') +"'>" + (value.candidate !== undefined ? value.candidate : '') + "</td><td data-column='"+ (consData.label.party !== undefined ? consData.label.party : 'PARTY') +"'>" + (value.party !== undefined ? value.party : '') + "</td></tr>"; 
            }else {
               if((value.win_loss !== undefined && value.win_loss != '') && value.win_loss == 'WON' && value.candidate_type == 'contesting'){
                 var win_loss_status = 'WON';
               }else if ((value.win_loss === undefined || value.win_loss == '') && !isWon){
                 var win_loss_status = 'Result Awaited';
               }else if ((value.win_loss !== undefined || value.win_loss != '') && isWon) {
                 var win_loss_status = 'LOST';
               }else if ((value.win_loss === undefined || value.win_loss == '') && isWon) {
                 var win_loss_status = 'LOST';
               } else {
                 var win_loss_status = '';
               }
               if ((value.win_loss !== undefined && value.win_loss != '') && value.win_loss == 'LEADING' && isLeading){
                 var win_loss_status = 'LEADING';
               }else if (isLeading) {
                   var win_loss_status = 'TRAILING';
               }
               html += "<tr><td data-column='"+ (consData.label.candidate_name !== undefined ? consData.label.candidate_name : 'CANDIDATE NAME') +"'>" + (value.candidate !== undefined ? value.candidate : '') + "</td><td data-column='"+ (consData.label.party !== undefined ? consData.label.party : 'PARTY') +"'>" + (value.party !== undefined ? value.party : '') + "</td><td data-column='"+ (consData.label.status !== undefined ? consData.label.status : 'STATUS') +"'>" + win_loss_status + "</td></tr>";
            }
            
        }
    })
    if (consData.live !== undefined && consData.live != "1") {
        var th = "<tr><th>"+ (consData.label.candidate_name !== undefined ? consData.label.candidate_name : 'CANDIDATE NAME') +"</th><th>"+ (consData.label.party !== undefined ? consData.label.party : 'PARTY') +"</th></tr>";
        jQuery("#other-candidates table thead").html(th);
        jQuery("#other-candidates table tbody").html(html);
        jQuery("#other-candidates-past").hide();
        jQuery("#other-candidates").show();
        jQuery("#other-candidates").removeClass('hide');
        if (consData.lbl_otherscandidate !== undefined) {
            jQuery("#other-candidates .heading").html(consData.lbl_otherscandidate);
        } else {
            jQuery("#other-candidates .heading").html('Other Candidates');
        }
    } else {
        var th = "<tr><th>"+ (consData.label.candidate_name !== undefined ? consData.label.candidate_name : 'CANDIDATE NAME') +"</th><th>"+ (consData.label.party !== undefined ? consData.label.party : 'PARTY') +"</th><th>"+(consData.label.status !== undefined ? consData.label.status : 'STATUS')+"</th></tr>";
        jQuery("#other-candidates").hide();
        jQuery("#other-candidates-past").show();
        jQuery("#other-candidates-past").removeClass('hide');
        jQuery("#other-candidates-past table thead").html(th);
        jQuery("#other-candidates-past table tbody").html(html);
        if (consData.lbl_otherscandidate !== undefined) {
            jQuery("#other-candidates-past .heading").html(consData.lbl_otherscandidate);
        } else {
            jQuery("#other-candidates-past .heading").html('Other Candidates');
        }
    }
}
