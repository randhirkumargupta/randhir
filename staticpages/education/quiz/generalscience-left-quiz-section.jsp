<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 388px;top:28px;}
	
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
	<div class="q-header"><h3>General Science</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Quiz on General Science: Basic questions and answers to help you prepare for exams</h2>
		<div class="left-quiz-section">
	    	<form name="tourismQuizForm" action="quiz-result.jsp" method="post" id="tourismQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						
						<div class="q-box"><strong>Q</strong>1</div>
						
						<div class="q-pool">
							<p>Brass gets discolored in air because of the presence of which of the following gases in air?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Oxygen"/>
								  <label for="q1"><span></span>Oxygen</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Hydrogen Sulphide"/>
								  <label for="q1"><span></span>Hydrogen Sulphide</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Carbon dioxide"/>
								  <label for="q1"><span></span>Carbon dioxide</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Nitrogen"/>
								  <label for="q1"><span></span>Nitrogen</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Who invented Jet Engine?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Sir Frank Whittle"/>
								  <label for="q2"><span></span>Sir Frank Whittle</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Gottlieb Daimler" />
								  <label for="q2"><span></span>Gottlieb Daimler</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Roger Bacon" />
								  <label for="q2"><span></span>Roger Bacon</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Lewis E. Waterman" />
								  <label for="q2"><span></span>Lewis E. Waterman</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>What is the chemical name for Quartz crystals that are normally used in quartz watches?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Silicon Dioxide" />
								  <label for="q3"><span></span>Silicon Dioxide</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Germanium Oxide" />
								  <label for="q3"><span></span>Germanium Oxide</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Sodium Silicate" />
								  <label for="q3"><span></span>Sodium Silicate</label>
							</li>
														<li>
								<input type="radio" id="q3" name="ques3" value="Sodium Sulphate" />
								  <label for="q3"><span></span>Sodium Sulphate</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Who designed the first hand glider?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Leonardo DaVinci" />
								  <label for="q4"><span></span>Leonardo DaVinci</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="The Wright brothers" />
								  <label for="q4"><span></span>The Wright brothers</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Galileo" />
								  <label for="q4"><span></span>Galileo</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Francis Rogallo" />
								  <label for="q4"><span></span>Francis Rogallo</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>Which of the following is used as a lubricant?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="Iron Oxide" />
								  <label for="q5"><span></span>Iron Oxide</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="Graphite" />
								  <label for="q5"><span></span>Graphite</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Diamond"/>
								  <label for="q5"><span></span>Diamond</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="Silica"/>
								  <label for="q5"><span></span>Silica</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Which of the following is not a function of bones?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Place for muscle attachment" />
								  <label for="q6"><span></span>Place for muscle attachment</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Protection of vital organs" />
								  <label for="q6"><span></span>Protection of vital organs</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Secretion of hormones for calcium regulation in blood and bones" />
								  <label for="q6"><span></span>Secretion of hormones for calcium regulation in blood and bones</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Production of blood corpuscles" />
								  <label for="q6"><span></span>Production of blood corpuscles</label>
							</li>							
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Myopia is connected with which organ?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Ears" />
								  <label for="q7"><span></span>Ears</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Eyes" />
								  <label for="q7"><span></span>Eyes</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Bones" />
								  <label for="q7"><span></span>Bones</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Heart" />
								  <label for="q7"><span></span>Heart</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>8</div>
						<div class="q-pool">
						   <p>Who is called the Father of Atom Bomb?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q8" name="ques8" value="Albert Einstein" />
								  <label for="q8"><span></span>Albert Einstein</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="Isaac Newton" />
								  <label for="q8"><span></span>Isaac Newton</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques8" value="Robert J. Oppenheimer" />
								  <label for="q8"><span></span>Robert J. Oppenheimer</label>
							</li>
							<li>
								<input type="radio" id="q8" name="ques7" value="Enrico Fermi" />
								  <label for="q8"><span></span>Enrico Fermi</label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>9</div>
						<div class="q-pool">
						   <p>Which is the smallest flowering plant is?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q9" name="ques9" value="Marigold" />
								  <label for="q9"><span></span>Marigold</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Worffia" />
								  <label for="q9"><span></span>Worffia</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Lavender" />
								  <label for="q9"><span></span>Lavender</label>
							</li>
							<li>
								<input type="radio" id="q9" name="ques9" value="Chrysanthemum" />
								  <label for="q9"><span></span>Chrysanthemum </label>
							</li>							
						</ul>
					</div>
				</div>
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>10</div>
						<div class="q-pool">
						   <p>What are the gases used in different types of welding?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q10" name="ques10" value="oxygen, acetylene and argon" />
								  <label for="q10"><span></span>oxygen, acetylene and argon</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="oxygen and hydrogen" />
								  <label for="q10"><span></span>oxygen and hydrogen</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="oxygen and acetylene" />
								  <label for="q10"><span></span>oxygen and acetylene</label>
							</li>
							<li>
								<input type="radio" id="q10" name="ques10" value="oxygen, hydrogen, acetylene and nitrogen" />
								  <label for="q10"><span></span>oxygen, hydrogen, acetylene and nitrogen </label>
							</li>							
						</ul>
					</div>
				</div>								
				<input type="hidden" name="resultGeneralScienceQuizId" value="resultGeneralScienceQuizId" id="resultGeneralScienceQuizId"/>
				<input type="hidden" name="GeneralSciencet10ques" value="GeneralSciencet10ques" id="GeneralSciencet10ques"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="tourismResult(tourismQuizForm);"/>
				</div>
			</form>    
	    </div>
	<!--left-quiz-section end-->
</div>
<!--##left-quiz-section end##-->




<script>
	function tourismResult(form) {
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
		for(index = 0; index < form.ques8.length; index++) {
			if(form.ques8[index].checked)
				result = result + "#" + "q8-" + form.ques8[index].value;
		}
		for(index = 0; index < form.ques9.length; index++) {
			if(form.ques9[index].checked)
				result = result + "#" + "q9-" + form.ques9[index].value;
		}
		for(index = 0; index < form.ques10.length; index++) {
			if(form.ques10[index].checked)
				result = result + "#" + "q10-" + form.ques10[index].value;
		}
		document.getElementById("resultGeneralScienceQuizId").value = result;
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