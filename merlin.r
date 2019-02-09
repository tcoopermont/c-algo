library(gtools)
library(dplyr)

t <- permutations(9,3,1:9,repeats.allowed=TRUE)
dt <- data.frame(t)
# one blinking
dt1 <- filter(dt,X1 == 1 | X2 == 2 | X3 == 3)
dt1 <- filter(dt1,X1 == 4 | X2 == 5 | X3 == 6)

#one blink one solid
can remove current position
op <- c(7,8,9)

dt2 <- filter(dt1,X1 %in% op  | X2 %in% op | X3 %in% op)


dt3 <- filter(dt2,X1 == 1 | X2 == 5 | X3 == 7)

#no hits
dt4 <- filter(dt3,X1 != 1 & X2 != 5 & X3 != 8)

