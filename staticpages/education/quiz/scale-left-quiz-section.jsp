<link href='http://fonts.googleapis.com/css?family=Roboto:700,500,400,900' rel='stylesheet' type='text/css' />

<style>
	#left-quiz-section{ width:675px; margin:0 auto;font-family:Roboto; background:#FFFFFF;}
	.q-header{margin-bottom:10px;}
	.q-header{ background:#fffde8 url('http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/CATEGORY-BAND.png')no-repeat;
	 width:675px; height:142px; position:relative;}
	 .q-header h3 {font-family: roboto;font-size: 23px;color: #FFFFFF;position: absolute;left:410px;top:28px;}
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

	<div class="q-header"><h3>SCALE</h3></div>
		<h2 style="font-size: 25px;margin-left: 12px;margin-bottom: -10px;color: sandybrown;">Strech a tad bit and grow by an inch.</h2>
	    <div class="left-quiz-section">
	    	<form name="scaleQuizForm" action="quiz-result.jsp" method="post" id="scaleQuizFormId">
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>1</div>
						<div class="q-pool">
							<p>1 Quintal is equal to how many kilograms(kg)?<p>
						</div>
						
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q1" name="ques1" value="100"/>
								  <label for="q1"><span></span>100</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="1000"/>
								  <label for="q1"><span></span>1000</label>
							</li>
							<li>
								<input type="radio" id="q1" name="ques1"  value="10"/>
								  <label for="q1"><span></span>10</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>2</div>
						<div class="q-pool">
							<p>1 Yard is equal to how many feet?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q2" name="ques2" value="5"/>
								  <label for="q2"><span></span>5</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="10" />
								  <label for="q2"><span></span>10</label>
							</li>
							<li>
								<input type="radio" id="q2" name="ques2" value="3" />
								  <label for="q2"><span></span>3</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>3</div>
						<div class="q-pool">
						   <p>1 Mile is equal to how many kilometers(km)?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q3" name="ques3" value="1.6" />
								  <label for="q3"><span></span>1.6</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="2.54" />
								  <label for="q3"><span></span>2.54</label>
							</li>
							<li>
								<input type="radio" id="q3" name="ques3" value="3.14" />
								  <label for="q3"><span></span>3.14</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>4</div>
						<div class="q-pool">
						   <p>1 Acre is equal to how many square meters?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q4" name="ques4" value="4046" />
								  <label for="q4"><span></span>4046</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="100" />
								  <label for="q4"><span></span>100</label>
							</li>
							<li>
								<input type="radio" id="q4" name="ques4" value="50" />
								  <label for="q4"><span></span>50</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>5</div>
						<div class="q-pool">
						   <p>1 Furlong is equal to how many yards?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q5" name="ques5" value="220" />
								  <label for="q5"><span></span>220</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5" value="100" />
								  <label for="q5"><span></span>100</label>
							</li>
							<li>
								<input type="radio" id="q5" name="ques5"  value="350"/>
								  <label for="q5"><span></span>350</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>6</div>
						<div class="q-pool">
						   <p>1 Inch is equal to how many centimeters (cm)?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q6" name="ques6" value="3.14" />
								  <label for="q6"><span></span>3.14</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="2.54" />
								  <label for="q6"><span></span>2.54</label>
							</li>
							<li>
								<input type="radio" id="q6" name="ques6" value="9.8" />
								  <label for="q6"><span></span>9.8</label>
							</li>
						</ul>
					</div>
				</div>
				
				<div class="question-box">
					<div class="q-box-section">
						<div class="q-box"><strong>Q</strong>7</div>
						<div class="q-pool">
						   <p>1 foot is equal to how many centimenters (cm)?</p>
						</div>
						<ul class="radio-button-box">
							<li>
								<input type="radio" id="q7" name="ques7" value="30.48" />
								  <label for="q7"><span></span>30.48</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="40" />
								  <label for="q7"><span></span>40</label>
							</li>
							<li>
								<input type="radio" id="q7" name="ques7" value="50" />
								  <label for="q7"><span></span>50</label>
							</li>
						</ul>
					</div>
				</div>
				<input type="hidden" name="resultScale" value="resultScale" id="scaleResultId"/>
				
				<div class="quiz-button">
					<input type="image" src="http://itgd-mum-dev-static.s3.amazonaws.com/media/others/mediaintoday/indiatoday/education/quiz/submit.png" border="0" onclick="scaleResult(scaleQuizForm);"/>
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
		document.getElementById("scaleResultId").value = result;
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