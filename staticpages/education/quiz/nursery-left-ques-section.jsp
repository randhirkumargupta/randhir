<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.left-quiz-section{padding:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left: 355px;top:28px;}
	
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

	<div class="q-header"><h3>NURSERY RHYME</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Don't haha and try answering the old rhymes</h2>
		<div class="left-quiz-section">
	    	<form name="nurseryQuizForm" action="quiz-result.jsp" method="post" id="nurseryQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>Ringa Ringa Roses, Poket full of ___<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="Posies. Ashes ashes!"/>
								  <label for="q1"><span></span>Posies. Ashes ashes!</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Poses. Hashes hases!"/>
								  <label for="q1"><span></span>Poses. Hashes hases!</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="Roses Hushes hushses!"/>
								  <label for="q1"><span></span>Roses Hushes hushses!</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>Doe a deer, a female deer, ray of drop of ___</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="Golden Sun"/>
								  <label for="q2"><span></span>Golden Sun</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Sun Bun" />
								  <label for="q2"><span></span>Sun Bun</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="Fun" />
								  <label for="q2"><span></span>Fun</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>Rain rain go away, come again another day, ___ wants to play</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="Little Arthur" />
								  <label for="q3"><span></span>Little Arthur</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Little Arjun" />
								  <label for="q3"><span></span>Little Arjun</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="Little one" />
								  <label for="q3"><span></span>Little one</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>Jack and Jill went up the hill, to fetch a ___ of water</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="Pail" />
								  <label for="q4"><span></span>Pail</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Pale" />
								  <label for="q4"><span></span>Pale</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="Pael" />
								  <label for="q4"><span></span>Pael</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>London bridge is falling down, falling down falling down, ___</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="My dear lady" />
								  <label for="q5"><span></span>My dear lady</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="My fair lady" />
								  <label for="q5"><span></span>My fair lady</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="My wood and clay"/>
								  <label for="q5"><span></span>My wood and clay</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>Baba black sheep have you any wool, yes Sir yes Sir three bags full. One for the master and one for the ___</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="Dame" />
								  <label for="q6"><span></span>Dame</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="Lame" />
								  <label for="q6"><span></span>Lame</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="mame" />
								  <label for="q6"><span></span>mame</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>Humpty dumpty sat on a wall, humpty dumpty had a great fall, Threescore men and threescore more___</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="Couldn't place humpty as he was before" />
								  <label for="q7"><span></span>Couldn't place humpty as he was before</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Couln't hold him anymore" />
								  <label for="q7"><span></span>Couln't hold him anymore</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="Couldn't wait to ignore" />
								  <label for="q7"><span></span>Couldn't wait to ignore</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultNursery" value="resultNursery" id="resultNurseryId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="scaleResult(nurseryQuizForm);"/>
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
		document.getElementById("resultNurseryId").value = result;
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