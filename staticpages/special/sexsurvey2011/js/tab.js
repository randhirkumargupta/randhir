function changeMustWatch( name, arg, total_arg){
	
	for (var i=1;i <= total_arg;i++){
		if(i == arg ){
			document.getElementById( name+i+"_0").style.display="block";
			document.getElementById( name+i+"_1").style.display="none";
		}
		else{
			document.getElementById( name+i+"_0").style.display="none";
			document.getElementById( name+i+"_1").style.display="block";
		}
	}
}

