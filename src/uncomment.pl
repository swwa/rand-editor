#!/usr/local/bin/perl
$incomment = 0;
while (<>) {
	if (/^#.*ifdef.*COMMENT/) {
		print ;
		print "/*\n";
		$incomment = 1;
	}
	else {
		if(/^#.*endif/ && $incomment == 1) {
			print "*/\n";
			print;
			$incomment = 0;
		}
		else {
			print;
		}
	}
}
