<?php 


if (isset($_GET['status']))
{
	
	/* open file in write mode*/
	$myfile = fopen("status1.txt","w");  /* da kda object mn no3 file */
	
	if($_GET['status'] == 'on')
	{
		fwrite($myfile,'1');
		echo ("LED ON");
		header("Location: on.html");
	}
	elseif ($_GET['status'] == 'off')
	{
			fwrite($myfile,'0');
		echo ("LED OFF ");
		header("Location: off.html");
	}
	/* close file */ 
	fclose ($myfile);
}








?>