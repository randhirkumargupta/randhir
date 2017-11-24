/*
 * @file itg_octopus_api.js
 * Contains all functionality related to octopus
 */

var _octopus_background_process_holder = new Array();

jQuery( 'document' ).ready( function() {

  jQuery( '#itg-octopus-api-form #edit-start-date-timeEntry-popup-1' ).attr( 'placeholder', 'Time' );
  jQuery( '#itg-octopus-api-form #edit-end-date-timeEntry-popup-1' ).attr( 'placeholder', 'Time' );

  jQuery( ".octopus-slug-data" ).click( function() {
    var current_object = jQuery( this );
    console.log( 'Testing some data' );
    if ( current_object.parent().parent().parent().next().hasClass( 'octopus-slug-data-row' ) != false ) {
      current_object.parent().parent().parent().next().remove();
    }
    var base_url = Drupal.settings.baseUrl.baseUrl;
    var slug_id = jQuery( this ).attr( 'data' );
    jQuery.ajax( {
      url: base_url + '/slug-details/' + slug_id,
      type: 'post',
      data: { 'id': slug_id },
      beforeSend: function() {
        //current_object.closest( 'tr' ).siblings( '.octopus-slug-data-row' ).hide();
        current_object.closest( 'tr' ).after( '<tr class="octopus-slug-data-row" style="text-align: center;"><td colspan="11"><img width="50" src="' + Drupal.settings.itg_octopus_holder.settings.loader_url + '" alt=""/></td></tr>' );
      },
      success: function( data ) {
        jQuery.ajax( {
          url: base_url + '/itg-octopus-check-slug-inprogress',
          type: 'post',
          data: { 'id': slug_id },
          success: function( slug_in_progress ) {
            //current_object.closest( 'tr' ).siblings( '.octopus-slug-data-row' ).hide();
            current_object.closest( 'tr' ).next().css( 'text-align', 'left' );
            current_object.closest( 'tr' ).next().html( '<td colspan="11">' + data + '</td>' );
            current_object.css( 'pointer-events', 'none' );
            if ( slug_in_progress == 1 ) {
              current_object.closest( 'tr' ).next().find( '.slug-link' ).find( '.get-video' ).trigger( 'click' );
            }
          },
          error: function( xhr, desc, err ) {
            console.log( xhr );
            console.log( "Details: " + desc + "\nError:" + err );
          }
        } );

      },
      error: function( xhr, desc, err ) {
        console.log( xhr );
        console.log( "Details: " + desc + "\nError:" + err );
      }
    } );


  } );


  // Copying data from Octopus to dumping machine

  jQuery( "body" ).on( 'click', '.get-video', function() {
    // Getting current working object for further requirement
    var current_working_object = jQuery( this );

    var base_url = Drupal.settings.baseUrl.baseUrl;
    var slug_id = jQuery( this ).attr( 'data' );
    var attr_id = jQuery( this ).attr( 'attribute_id' );
    current_working_object.closest( 'tr' ).find( '.video-process-bar-' + attr_id ).show();
    current_working_object.closest( 'tr' ).find( '.video-process-bar-' + attr_id ).html( '<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Please wait.. Sending request to Server..</p></div>' );

    jQuery.ajax( {
      url: base_url + '/itg-octopus-sending-request-to-tv-team',
      type: 'post',
      data: { 'slug_id': slug_id, 'attr_id': attr_id },
      beforeSend: function() {
          current_working_object.closest( 'tr' ).find( '.video-process-bar-' + attr_id ).html( '<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>Wait..Getting response from server..</p></div>' );
      },
      success: function( data ) {
        _octopus_background_process_holder[attr_id] = setInterval( function() {
          console.log( current_working_object );
          jQuery.ajax( {
            url: base_url + '/itg-octopus-background-video-status',
            type: 'post',
            data: { 'id': data },
            beforeSend: function() {
            },
            success: function( datafinal ) {
              var datafinal_json = JSON.parse( datafinal );
              console.log( datafinal_json );
              setTimeout( function() {
                current_working_object.closest( 'tr' ).find( '.video-process-bar-' + attr_id ).html( '<div class="process-bar-data"><div class="progress">       <div class="bg-success progress-bar progress-bar-striped progress-bar-animated" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div></div><p>' + datafinal_json.message + '</p></div>' );
                if ( datafinal_json.type == 'final_success' ) {
                  setTimeout( function() {
                    clearInterval( _octopus_background_process_holder[attr_id] );
                    setTimeout( function() {
                      current_working_object.closest( 'tr' ).find( '.video-process-bar-' + attr_id ).hide();
                      current_working_object.closest( 'tr' ).find( '#file-video-article-' + attr_id ).show();
                      current_working_object.closest( 'tr' ).find( '#get-video-' + attr_id ).hide();
                    }, 5000 );
                    return;
                  }, 2000 );
                }
              }, 5000 );
            },
            error: function( xhr, desc, err ) {
              console.log( xhr );
              console.log( "Details: " + desc + "\nError:" + err );
            }
          } );

        }, 10000 ); // Execute every 10 seconds.


      },
      error: function( xhr, desc, err ) {
        console.log( xhr );
        console.log( "Details: " + desc + "\nError:" + err );
      }
    } );

  } );

  // Handler for file video
  jQuery( "body" ).on( 'click', '.file-video', function() {
    var o_current_object = jQuery( this );
    var o_base_url = Drupal.settings.baseUrl.baseUrl;
    var o_slug_id = jQuery( this ).attr( 'data' );
    var o_attr_id = jQuery( this ).attr( 'attribute_id' );
    jQuery.ajax( {
      url: o_base_url + '/itg-octopus-file-video',
      type: 'post',
      data: { 'slug_id': o_attr_id },
      beforeSend: function() {
      },
      success: function( fdata ) {
        window.location.href = fdata;
      },
      error: function( xhr, desc, err ) {
        console.log( xhr );
        console.log( "Details: " + desc + "\nError:" + err );
      }
    } );
  } );


  jQuery( "body" ).on( 'click', '.remove-data', function() {
    //jQuery(this).parent().parent().remove();
    try {
      var attr_to_cancel = jQuery( this ).closest( 'tr' ).find( '.get-video' ).attr( 'attribute_id' );
      clearInterval( _octopus_background_process_holder[attr_to_cancel] );
      jQuery( this ).parent().parent().prev().find( '.octopus-slug-data' ).css( 'pointer-events', 'auto' );
      jQuery( this ).parent().parent().hide();
    } catch ( e ) {
      console.warn( 'There is some problem while handling remove request due to Error' + e.message );
    }
  } );


} );

/**
 * Code started for restoring the browser session
 */
jQuery( 'document' ).ready( function( e ) {
  if ( window.location.href.indexOf( "rundown-listing" ) > -1 ) {
    var o_base_url = Drupal.settings.baseUrl.baseUrl;
    jQuery.ajax( {
      url: o_base_url + '/itg-octopus-restore-back-g-process',
      type: 'post',
      data: { },
      beforeSend: function() {
      },
      success: function( fdata ) {
        jQuery( '.views-table' ).find( 'tr' ).each( function() {
          var active_attribute = jQuery( this ).find( '.octopus-slug-data' ).attr( 'data' );
          console.log( active_attribute );
          console.log( fdata.indexOf( active_attribute ) );
          if ( fdata.indexOf( active_attribute ) > 0 ) {
            jQuery( this ).find( '.octopus-slug-data' ).trigger( 'click' );
          }
        } );
      },
      error: function( xhr, desc, err ) {
        console.log( xhr );
        console.log( "Details: " + desc + "\nError:" + err );
      }
    } );
  }
} );