#!/usr/bin/env perl
$stacksize = $ARGV[0];
$min = $ARGV[1];
$max = $ARGV[2];
@stack = ();

if ($stacksize < 0 || $min >= $max)
{
	print "Usage: ./genstack.pl stacksize min max";
}

for ($num = 0; $num < $stacksize; )
{
	$n = int(srand() % ($max - $min) + $min);
	if (!(grep { $_ eq $n } @stack))
	{
		push @stack, $n;
		$num++;
	}
}
print "@stack\n";