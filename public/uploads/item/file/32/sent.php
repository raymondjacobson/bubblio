<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
		<title>Alluring Spaces | Thank you!</title>
		<meta name="description" content="Alluring Spaces home staging, realty, and interior decorating services help to sell your home for a higher value." />
		<meta name="author" content="Alluring Spaces" />
		<meta name="viewport" content="width=device-width; initial-scale=1.0" />
		<base href="http://alluringspaces.com" />
		<link rel="shortcut icon" href="images/favicon.ico" />
		<link rel="stylesheet" href="css/columnal.css" type="text/css" media="screen" />
		<!--[if lt IE 9]>
		<link rel="stylesheet" href="css/ie.css" type="text/css" media="screen" />
		<![endif]-->
		<link rel="stylesheet" type="text/css" media="only screen and (max-device-width: 480px)" href="css/mobile.css" />
		<link rel="stylesheet" type="text/css" href="css/common.css">
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
		<script></script>
	</head>
	<body>
		<div class="container">
			<?php include("header.php"); ?>
			<div class="row body">
				<div class="col_8 headline">
					<?php $name = $_GET["name"] ?>
					<h1 style="font-style: normal; color:black; font-family: Georgia, Times New Roman, serif;">
						Thanks, <?php echo $name ?>.
					</h1>
					<p style="font-weight:bold;">WE'LL WRITE BACK SHORTLY!</p>
					<p>We do not share your information with anybody.</p>
				</div>
				<div class="col_4 last">
					<div class="topclip"
					style="
						background:url('http://www.alluringspaces.com/index_files/image490.jpg');
						background-repeat: no-repeat;
						background-position: center -60px;
						">
						
					</div>
				</div>
			</div>
			<?php include("footer.php"); ?>
		</div>
	</body>
</html>
