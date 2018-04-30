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
        setInterval(function () {
            getConstituencyData(Drupal.settings.json_url, Drupal.settings.constituency);
        }, 5000);
    }
});

function renderConstituencyBlocks(data, jsonKey) {
    if (data.candidate === undefined || data.candidate.length <= 0)
        return;

    var isWon = false;
    var isSeating = false;
    var wonCondidate = undefined;
    var seatingCondidate = undefined;
    var otherCondidates = [];
    jQuery.each(data.candidate, function (key, value) {
        if (value.win_loss !== undefined && value.win_loss == "WON" && !isWon) {
            isWon = true;
            wonCondidate = value;
        } else if (value.candidate_type == "seating") {
            isSeating = true;
            seatingCondidate = value;
        } else {
            otherCondidates.push(value);
        }
    });
    if (isWon) {
        otherCondidates.push(seatingCondidate);
        showWonConstituencyCandidatesHTML(wonCondidate, data, jsonKey);
    }
    if (!isWon && isSeating) {
        showWonConstituencyCandidatesHTML(seatingCondidate, data, jsonKey);
    }
    if (otherCondidates.length > 0) {
        showOthersConstituencyCandidatesHTML(otherCondidates, data);
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
    html += "<tr><td>Gender</td><td>" + (data.age !== undefined ? data.age : '') + "</td></tr>";
    html += "<tr><td>Education Qualification</td><td>" + (data.qualification !== undefined ? data.qualification : '') + "</td></tr>";
    html += "<tr><td>Profession</td><td>" + (data.profession !== undefined ? data.profession : '') + "</td></tr>";
    html += "<tr><td>Marital status</td><td>" + (data.marital_status !== undefined ? data.marital_status : '') + "</td></tr>";
    html += "<tr><td>Criminal Cases</td><td>" + (data.criminal_cases !== undefined ? data.criminal_cases : '') + "</td></tr>";
    html += "<tr><td>Assets</td><td>" + (data.assets !== undefined ? data.assets : '') + "</td></tr>";
    html += "<tr><td>Movable Assets</td><td>" + (data.moveable_assets !== undefined ? data.moveable_assets : '') + "</td></tr>";
    html += "<tr><td>Immovable Assets</td><td>" + (data.immovable_assets !== undefined ? data.immovable_assets : '') + "</td></tr>";
    html += "<tr><td>Income</td><td>" + (data.income !== undefined ? data.income : '') + "</td></tr>";
    html += "<tr><td>Spouse Dependants</td><td>" + (data.spouse_dependants !== undefined ? data.spouse_dependants : '') + "</td></tr>";
    jQuery("#constituency-top-chunk #candidates table tbody").html(html);
    if (consData.lbl_candidates !== undefined) {
        jQuery("#constituency-top-chunk #candidates .labels").html(consData.lbl_candidates);
    } else {
        jQuery("#constituency-top-chunk #candidates .labels").html('Candidates');
    }

    var mocHTML = "";
    mocHTML += "<tr><td>AC name</td><td>" + (constituencyName !== undefined ? constituencyName : '') + "</td></tr>";
    mocHTML += "<tr><td>AC No</td><td>" + (consData.id !== undefined ? consData.id : '') + "</td></tr>";
    mocHTML += "<tr><td>No of voters</td><td>" + (consData.voters_count !== undefined ? consData.voters_count : '') + "</td></tr>";
    mocHTML += "<tr><td>Area</td><td>" + (consData.district !== undefined ? consData.district : '') + "</td></tr>";
    mocHTML += "<tr><td>Sitting MLA's name</td><td>" + (data.candidate !== undefined ? data.candidate : '') + "</td></tr>";
    jQuery("#constituency-top-chunk #map-of-constituency table tbody").html(mocHTML);
    if (consData.svg !== undefined) {
        jQuery("#constituency-top-chunk #map-of-constituency #candidates-svg").html(consData.svg);
    }
    if (consData.lbl_mapofconstituency !== undefined) {
        jQuery("#constituency-top-chunk #map-of-constituency .labels").html(consData.lbl_mapofconstituency);
    } else {
        jQuery("#constituency-top-chunk #map-of-constituency .labels").html('Map of constituency');
    }
}

function showOthersConstituencyCandidatesHTML(data, consData) {
    var html = "";
    jQuery.each(data, function (key, value) {
        if (value !== undefined) {
            html += "<tr><td>" + (value.candidate !== undefined ? value.candidate : '') + "</td><td>" + (value.party !== undefined ? value.party : '') + "</td><td>" + (value.votes !== undefined ? value.votes : '') + "</td><td>" + (value.percentage_votes !== undefined ? value.percentage_votes : '') + "</td><td>" + (value.percentage_change !== undefined ? value.percentage_change : '') + "</td></tr>";
        }
    })
    if (consData.live !== undefined && consData.live == "1") {
        jQuery("#other-candidates table tbody").html(html);
        //jQuery("#other-candidates-past").hide();
        if (consData.lbl_otherscandidate !== undefined) {
            jQuery("#other-candidates .labels").html(consData.lbl_otherscandidate);
        } else {
            jQuery("#other-candidates .labels").html('Other Candidates');
        }
    } else {
        //jQuery("#other-candidates").hide();
        jQuery("#other-candidates-past table tbody").html(html);
        if (consData.lbl_otherscandidate !== undefined) {
            jQuery("#other-candidates-past .labels").html(consData.lbl_otherscandidate);
        } else {
            jQuery("#other-candidates-past .labels").html('Other Candidates');
        }
    }
}