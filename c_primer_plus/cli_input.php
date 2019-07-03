<?php       
while (($line = fgets(STDIN)) != "\n") {
    print_r('first loop: '. $line);
    while (($line = fgets(STDIN)) != "\n") {
        print_r("second loop: " .$line);
    }
}

