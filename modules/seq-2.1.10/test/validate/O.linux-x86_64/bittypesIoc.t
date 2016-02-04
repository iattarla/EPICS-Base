my $pid = fork();
die "fork failed: $!" unless defined($pid);
if (!$pid) {
  exec("/usr/local/epics/base/bin/linux-x86_64/softIoc -D /usr/local/epics/base/dbd/softIoc.dbd -S -d ../bittypes.db");
  die "exec failed: $!";
}
system("./bittypes -S");
kill 9, $pid or die "kill failed: $!";
