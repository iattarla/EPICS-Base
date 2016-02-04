my $pid = fork();
die "fork failed: $!" unless defined($pid);
if (!$pid) {
  exec("/usr/local/epics/base/bin/linux-x86_64/softIoc -D /usr/local/epics/base/dbd/softIoc.dbd -S -d ../norace.db");
  die "exec failed: $!";
}
system("./norace -S");
kill 9, $pid or die "kill failed: $!";
