	$(document).ready(function(){
		$('.mob_nav').click(function(){
			$('.navigation').slideToggle();
		});
		$('.navigation').mouseleave(function(){
			$(this).slideUp();
		});
		
		$('li.sm_t').click(function(){
								
						$('ul.tp_tg').slideToggle();
							 })
	})
	
	$(function() {
	var Accordion = function(el, multiple) {
		this.el = el || {};
		this.multiple = multiple || false;

		// Variables privadas
		var links = this.el.find('.link');
		// Evento
		links.on('click', {el: this.el, multiple: this.multiple}, this.dropdown)
	}

	Accordion.prototype.dropdown = function(e) {
		var $el = e.data.el;
			$this = $(this),
			$next = $this.next();

		$next.slideToggle();
		$this.parent().toggleClass('open');

		if (!e.data.multiple) {
			$el.find('.submenu').not($next).slideUp().parent().removeClass('open');
		};
	}	

	var accordion = new Accordion($('#accordion'), false);
});
$(document).ready(function(){
$('.pos').click(function(){
	$('em').removeClass('opens01');
	$('ul.submenus01').slideUp();
	$('ul.submenus').slideToggle();
	$('.pos').toggleClass('opens');
	})
$('.spos01').click(function(){
	$('em').removeClass('opens');
	$('ul.submenus').slideUp();
	$('ul.submenus01').slideToggle();
	$('.pos01').toggleClass('opens01');
	})	
		$(function (){
		createMarquee({
		duration:20000, 
		padding:10, 
	})
	});
	});
	