(function( $ ){

	var $serialScroll = $.serialScroll = function( settings ){
		$.scrollTo.window().serialScroll( settings );
	};

	//Many of these defaults, belong to jQuery.ScrollTo, check it's demo for an example of each option.
	$serialScroll.defaults = {//the defaults are public and can be overriden.
		duration:1000, //how long to animate.
		axis:'x', //which of top and left should be scrolled
		event:'click', //on which event to react.
		start:0, //first element (zero-based index)
		step:1, //how many elements to scroll on each action
		lock:true,//ignore events if already animating
		cycle:true, //cycle endlessly ( constant velocity )
		constant:true //use contant speed ?
		/*
		navigation:null,//if specified, it's a selector a collection of items to navigate the container
		target:null, //if specified, it's a selector to the element to be scrolled.
		interval:0, //it's the number of milliseconds to automatically go to the next
		lazy:false,//go find the elements each time (allows AJAX or JS content, or reordering)
		stop:false, //stop any previous animations to avoid queueing
		force:false,//force the scroll to the first element on start ?
		jump: false,//if true, when the event is triggered on an element, the pane scrolls to it
		items:null, //selector to the items (relative to the matched elements)
		prev:null, //selector to the 'prev' button
		next:null, //selector to the 'next' button
		onBefore: function(){}, //function called before scrolling, if it returns false, the event is ignored
		exclude:0 //exclude the last x elements, so we cannot scroll past the end
		*/
	};

	$.fn.serialScroll = function( settings ){
		settings = $.extend( {}, $serialScroll.defaults, settings );
		var event = settings.event, //this one is just to get shorter code when compressed
			step = settings.step, // idem
			lazy = settings.lazy;//idem

		return this.each(function(){
			var 
				context = settings.target ? this : document, //if a target is specified, then everything's relative to 'this'.
				$pane = $(settings.target || this, context),//the element to be scrolled (will carry all the events)
				pane = $pane[0], //will be reused, save it into a variable
				items = settings.items, //will hold a lazy list of elements
				active = settings.start, //active index
				auto = settings.interval, //boolean, do auto or not
				nav = settings.navigation, //save it now to make the code shorter
				timer; //holds the interval id

			if( !lazy )//if not lazy, go get the items now
				items = getItems();

			if( settings.force )
				jump( {}, active );//generate an initial call

			// Button binding, optionall
			$(settings.prev||[], context).bind( event, -step, move );
			$(settings.next||[], context).bind( event, step, move );

			// Custom events bound to the container
			if( !pane.ssbound )//don't bind more than once
				$pane
					.bind('prev.serialScroll', -step, move ) //you can trigger with just 'prev'
					.bind('next.serialScroll', step, move ) //for example: $(container).trigger('next');
					.bind('goto.serialScroll', jump ); //for example: $(container).trigger('goto', [4] );
			if( auto )
				$pane
					.bind('start.serialScroll', function(e){
						if( !auto ){
							clear();
							auto = true;
							next();
						}
					 })
					.bind('stop.serialScroll', function(){//stop a current animation
						clear();
						auto = false;
					});
			$pane.bind('notify.serialScroll', function(e, elem){//let serialScroll know that the index changed externally
				var i = index(elem);
				if( i > -1 )
					active = i;
			});
			pane.ssbound = true;//avoid many bindings

			if( settings.jump )//can't use jump if using lazy items and a non-bubbling event
				(lazy ? $pane : getItems()).bind( event, function( e ){
					jump( e, index(e.target) );
				});

			if( nav )
				nav = $(nav, context).bind(event, function( e ){
					e.data = Math.round(getItems().length / nav.length) * nav.index(this);
					jump( e, this );
				});

			function move( e ){
				e.data += active;
				jump( e, this );
			};
			function jump( e, button ){
				if( !isNaN(button) ){//initial or special call from the outside $(container).trigger('goto',[index]);
					e.data = button;
					button = pane;
				}

				var
					pos = e.data, n,
					real = e.type, //is a real event triggering ?
					$items = settings.exclude ? getItems().slice(0,-settings.exclude) : getItems(),//handle a possible exclude
					limit = $items.length,
					elem = $items[pos],
					duration = settings.duration;

				if( real )//real event object
					e.preventDefault();

				if( auto ){
					clear();//clear any possible automatic scrolling.
					timer = setTimeout( next, settings.interval ); 
				}

				if( !elem ){ //exceeded the limits
					n = pos < 0 ? 0 : limit - 1;
					if( active != n )//we exceeded for the first time
						pos = n;
					else if( !settings.cycle )//this is a bad case
						return;
					else
						pos = limit - n - 1;//invert, go to the other side
					elem = $items[pos];
				}

				if( !elem || real && active == pos || //could happen, save some CPU cycles in vain
					settings.lock && $pane.is(':animated') || //no animations while busy
					real && settings.onBefore && //callback returns false ?
					settings.onBefore.call(button, e, elem, $pane, getItems(), pos) === false ) return;

				if( settings.stop )
					$pane.queue('fx',[]).stop();//remove all its animations

				if( settings.constant )
					duration = Math.abs(duration/step * (active - pos ));//keep constant velocity

				$pane
					.scrollTo( elem, duration, settings )//do scroll
					.trigger('notify.serialScroll',[pos]);//in case serialScroll was called on this elem more than once.
			};
			function next(){//I'll use the namespace to avoid conflicts
				$pane.trigger('next.serialScroll');
			};
			function clear(){
				clearTimeout(timer);
			};
			function getItems(){
				return $( items, pane );
			};
			function index( elem ){
				if( !isNaN(elem) ) return elem;//number
				var $items = getItems(), i;
				while(( i = $items.index(elem)) == -1 && elem != pane )//see if it matches or one of its ancestors
					elem = elem.parentNode;
				return i;
			};
		});
	};

})( jQuery );

;(function( $ ){

	var $scrollTo = $.scrollTo = function( target, duration, settings ){
		$scrollTo.window().scrollTo( target, duration, settings );
	};

	$scrollTo.defaults = {
		axis:'y',
		duration:1
	};

	//returns the element that needs to be animated to scroll the window
	$scrollTo.window = function(){
		return $( $.browser.safari ? 'body' : 'html' );
	};

	$.fn.scrollTo = function( target, duration, settings ){
		if( typeof duration == 'object' ){
			settings = duration;
			duration = 0;
		}
		settings = $.extend( {}, $scrollTo.defaults, settings );
		duration = duration || settings.speed || settings.duration;//speed is still recognized for backwards compatibility
		settings.queue = settings.queue && settings.axis.length > 1;//make sure the settings are given right
		if( settings.queue )
			duration /= 2;//let's keep the overall speed, the same.
		settings.offset = both( settings.offset );
		settings.over = both( settings.over );

		return this.each(function(){
			var elem = this, $elem = $(elem),
				t = target, toff, attr = {},
				win = $elem.is('html,body');
			switch( typeof t ){
				case 'number'://will pass the regex
				case 'string':
					if( /^([+-]=)?\d+(px)?$/.test(t) ){
						t = both( t );
						break;//we are done
					}
					t = $(t,this);// relative selector, no break!
				case 'object':
					if( t.is || t.style )//DOM/jQuery
						toff = (t = $(t)).offset();//get the real position of the target 
			}
			$.each( settings.axis.split(''), function( i, axis ){
				var Pos	= axis == 'x' ? 'Left' : 'Top',
					pos = Pos.toLowerCase(),
					key = 'scroll' + Pos,
					act = elem[key],
					Dim = axis == 'x' ? 'Width' : 'Height',
					dim = Dim.toLowerCase();

				if( toff ){//jQuery/DOM
					attr[key] = toff[pos] + ( win ? 0 : act - $elem.offset()[pos] );

					if( settings.margin ){//if it's a dom element, reduce the margin
						attr[key] -= parseInt(t.css('margin'+Pos)) || 0;
						attr[key] -= parseInt(t.css('border'+Pos+'Width')) || 0;
					}
					
					attr[key] += settings.offset[pos] || 0;//add/deduct the offset
					
					if( settings.over[pos] )//scroll to a fraction of its width/height
						attr[key] += t[dim]() * settings.over[pos];
				}else
					attr[key] = t[pos];//remove the unnecesary 'px'

				if( /^\d+$/.test(attr[key]) )//number or 'number'
					attr[key] = attr[key] <= 0 ? 0 : Math.min( attr[key], max(Dim) );//check the limits

				if( !i && settings.queue ){//queueing each axis is required					
					if( act != attr[key] )//don't waste time animating, if there's no need.
						animate( settings.onAfterFirst );//intermediate animation
					delete attr[key];//don't animate this axis again in the next iteration.
				}
			});			
			animate( settings.onAfter );			

			function animate( callback ){
				$elem.animate( attr, duration, settings.easing, callback && function(){
					callback.call(this, target);
				});
			};
			function max( Dim ){
				var el = win ? $.browser.opera ? document.body : document.documentElement : elem;
				return el['scroll'+Dim] - el['client'+Dim];
			};
		});
	};

	function both( val ){
		return typeof val == 'object' ? val : { top:val, left:val };
	};

})( jQuery );


$(document).ready(function () {
    var $panels = $('#slider .scrollContainer > div');
    var $container = $('#slider .scrollContainer');
    var horizontal = true;
    if (horizontal) {
        $container.css('width', $panels[0].offsetWidth * $panels.length);
    }
    var $scroll = $('#slider .scroll').css('overflow', 'hidden');
    var $navigation = $('#slider .navigation');
    $navigation
        .before('<img class="scrollButtons left" src="http://indiatoday.intoday.in/images/on-the-stand-left.jpg" />')
        .after('<img class="scrollButtons right" src="/staticpages/main/images/on-the-stand-right.jpg" />');

    function selectNav() {
       var $this = $(this);var ml = 0;    
		if ($this.parents("li").hasClass('one'))  {ml=0;} if ($this.parents("li").hasClass('two')){ ml=0;} if ($this.parents("li").hasClass('three')) { ml=-260;}   
		if ($this.parents("li").hasClass('four')) {  ml=-260; }    if ($this.parents("li").hasClass('five')) {  ml=-520; } if ($this.parents("li").hasClass('six'))  { ml=-520; }
	
  $('ul.navigation').stop().animate({ marginLeft: ml}, 400);
        
        $(this)
            .parents('ul:first')
                .find('a')
                    .removeClass('active')
                .end()
            .end()
            .addClass('active');
        
    }

    function trigger(data) {
        var el = $('#slider .navigation').find('a[href$="' + data.id + '"]').get(0);
        selectNav.call(el);
    }

    if (window.location.hash) {
        trigger({ id : window.location.hash.substr(1) });
    } else {
        $('ul.navigation a:first').click();
    }


    var offset = parseInt((horizontal ? 
        $container.css('paddingTop') : 
        $container.css('paddingLeft')) 
        || 0) * -1;


    var scrollOptions = {
        target: $scroll,

        items: $panels,

        navigation: '.navigation a',

        prev: 'img.left', 
        next: 'img.right',

        axis: 'xy',

        onAfter: trigger,

        offset: offset,

        duration: 500,

        easing: 'swing'
    };

    $('#slider').serialScroll(scrollOptions);

    //$.localScroll(scrollOptions);

    scrollOptions.duration = 1;
   // $.localScroll.hash(scrollOptions);

});