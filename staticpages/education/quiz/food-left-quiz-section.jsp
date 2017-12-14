
<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 420px;top:28px;}
	
	.left-quiz-section{padding:10px;}
	.q-box-section{ width:660px; height:66px; background:#fffde8;}
	.q-box{ width:40px; height:66px; line-height:66px; background:#f86e6c; text-align:center; color:#FFFFFF; float:left;}
	.q-box strong{ font-size:22px; font-weight:normal;}
	.q-pool {width: 580px;height: 66px;font-size: 16px;color: #9d9b9e;margin-left: 20px;float: left;}
	.radio-button-box{margin-left:40px;}
	.radio-button-box li{ list-style:none; float:left; margin-right:60px;padding: 18px 15px;}

	.active{
		background: #fffde8;padding: 18px 15px;-moz-border-radius: 0px 0px 10px 10px;
		-webkit-border-radius: 0px 0px 10px 10px;
		border-radius: 0px 0px 10px 10px;
		/*IE 7 AND 8 DO NOT SUPPORT BORDER RADIUS*/
	}
	.question-box{width: 675px;margin-bottom: 50px;float: left;}
	.styledRadio{  float:left; margin-right:5px; outline:0;}
	.radio-button-box label{ font-size:16px; color:#9d9b9e}
	.quiz-button{ width:675px; text-align:center; margin-top:20px;}

</style>

<div id="left-quiz-section">

	<div class="q-header"><h3>FOOD</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Are you a Connoisseur of food? Let's find out</h2>
		<div class="left-quiz-section">
	    	<form name="foodQuizForm" action="quiz-result.jsp" method="post" id="foodQuizFormId">
	    		<input type="hidden" name="foddPart" value="null"/>
	    		
						<input type="hidden" name="foddPart" value="null"/> 
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>1</div>
								<div class="q-pool">
									<p>Where are French fries originally from?<p>
								</div>
								
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q1" name="ques1" value="France"/>
										  <label for="q1"><span></span>France</label>
									</li>
									<li>
										<input type="radio" id="q1" name="ques1"  value="Belgium"/>
										  <label for="q1"><span></span>Belgium</label>
									</li>
									<li>
										<input type="radio" id="q1" name="ques1"  value="India"/>
										  <label for="q1"><span></span>India</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>2</div>
								<div class="q-pool">
									<p>Name the fruit, which has its seeds on the outside.</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q2" name="ques2" value="Strawberry"/>
										  <label for="q2"><span></span>Strawberry</label>
									</li>
									<li>
										<input type="radio" id="q2" name="ques2" value="Papaya" />
										  <label for="q2"><span></span>Papaya</label>
									</li>
									<li>
										<input type="radio" id="q2" name="ques2" value="Blueberry" />
										  <label for="q2"><span></span>Blueberry</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>3</div>
								<div class="q-pool">
								   <p>Where was the first Burger King opened?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q3" name="ques3" value="Australia" />
										  <label for="q3"><span></span>Australia</label>
									</li>
									<li>
										<input type="radio" id="q3" name="ques3" value="Italy" />
										  <label for="q3"><span></span>Italy</label>
									</li>
									<li>
										<input type="radio" id="q3" name="ques3" value="Florida" />
										  <label for="q3"><span></span>Florida</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>4</div>
								<div class="q-pool">
								   <p>Pop corns were invented by whom?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q4" name="ques4" value="Aztec Indians" />
										  <label for="q4"><span></span>Aztec Indians</label>
									</li>
									<li>
										<input type="radio" id="q4" name="ques4" value="Raffaele Esposito" />
										  <label for="q4"><span></span>Raffaele Esposito</label>
									</li>
									<li>
										<input type="radio" id="q4" name="ques4" value="King Tang" />
										  <label for="q4"><span></span>King Tang</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>5</div>
								<div class="q-pool">
								   <p>Where was the fortune cookie invented?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q5" name="ques5" value="China" />
										  <label for="q5"><span></span>China</label>
									</li>
									<li>
										<input type="radio" id="q5" name="ques5" value="California" />
										  <label for="q5"><span></span>California</label>
									</li>
									<li>
										<input type="radio" id="q5" name="ques5"  value="America"/>
										  <label for="q5"><span></span>America</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>6</div>
								<div class="q-pool">
								   <p>Name the oldest known vegetable.</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q6" name="ques6" value="Mushroom" />
										  <label for="q6"><span></span>Mushroom</label>
									</li>
									<li>
										<input type="radio" id="q6" name="ques6" value="Cabbage" />
										  <label for="q6"><span></span>Cabbage</label>
									</li>
									<li>
										<input type="radio" id="q6" name="ques6" value="Peas" />
										  <label for="q6"><span></span>Peas</label>
									</li>
								</ul>
							</div>
						</div>
						
						<div class="question-box">
							<div class="q-box-section">
								<div class="q-box"><strong>Q</strong>7</div>
								<div class="q-pool">
								   <p>What does buttermilk not contain?</p>
								</div>
								<ul class="radio-button-box">
									<li>
										<input type="radio" id="q7" name="ques7" value="Butter" />
										  <label for="q7"><span></span>Butter</label>
									</li>
									<li>
										<input type="radio" id="q7" name="ques7" value="Milk" />
										  <label for="q7"><span></span>Milk</label>
									</li>
									<li>
										<input type="radio" id="q7" name="ques7" value="Cream" />
										  <label for="q7"><span></span>Cream</label>
									</li>
								</ul>
							</div>
						</div>
				
				<input type="hidden" name="resultFoodQuiz" value="resultFoodQuiz" id="resultFoodQuizId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="scaleResult(foodQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->
<script>
	function scaleResult(form) {
		var result="";
		for(index = 0; index < form.ques1.length; index++) {
			if(form.ques1[index].checked)
				result = "q1-" + form.ques1[index].value;
		}
		for(index = 0; index < form.ques2.length; index++) {
			if(form.ques2[index].checked)
				result = result + "#" + "q2-" + form.ques2[index].value;
		}
		for(index = 0; index < form.ques3.length; index++) {
			if(form.ques3[index].checked)
				result = result + "#" + "q3-" + form.ques3[index].value;
		}
		for(index = 0; index < form.ques4.length; index++) {
			if(form.ques4[index].checked)
				result = result + "#" + "q4-" + form.ques4[index].value;
		}
		for(index = 0; index < form.ques5.length; index++) {
			if(form.ques5[index].checked)
				result = result + "#" + "q5-" + form.ques5[index].value;
		}
		for(index = 0; index < form.ques6.length; index++) {
			if(form.ques6[index].checked)
				result = result + "#" + "q6-" + form.ques6[index].value;
		}
		for(index = 0; index < form.ques7.length; index++) {
			if(form.ques7[index].checked)
				result = result + "#" + "q7-" + form.ques7[index].value;
		}
		document.getElementById("resultFoodQuizId").value = result;
	}
	
	var selectedLi, elements, makeActive;
	selectedLi = '.radio-button-box li';
	elements = document.querySelectorAll(selectedLi);
	
	makeActive = function() {
		for(var index=0; index < elements.length; index++) {
			elements[index].classList.remove('active');
			this.classList.add('active');
		}		
	};
	for(var index=0; index < elements.length; index++)
		elements[index].addEventListener('mousedown', makeActive);
	
</script>