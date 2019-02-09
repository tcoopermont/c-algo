library(gtools)
library(dplyr)

t <- permutations(9,3,1:9,repeats.allowed=TRUE)
dt <- data.frame(t)

bl1_so0 <- function(dat,x,y,z){
  filter(dat,X1 == x | X2 == y | X3 == z)

}

noHits <- function(dat,x,y,z){
  list <- c(x,y,z)
  filter(dat,!X1 %in% list & !X2 %in% list & !X3 %in% list)
}

bl1_so1 <- function(dat,x,y,z){
  g1 <- filter(dat,(X1 == x & X2 == z & X3 != z) | (X1 == x & X3 == y & X2 != y)) 
  g2 <- filter(dat,(X2 == y & X1 == z & X3 != z) | (X2 == y & X3 == x & X1 != x)) 
  g3 <- filter(dat,(X3 == z & X1 == y & X2 != y) | (X3 == z & X2 == x & X1 != x)) 

  unique(bind_rows(g1,g2,g3)) %>% arrange(X1,X2,X3)
  
}

checkHits <- function(answer,guess){

  blinks <- 0
  for(i in 1:3){
    if(guess[i] == answer[i]){
      blinks <- blinks + 1
    }
  }
  sAnswer <- sort(answer)
  sGuess <- sort(guess)
  solids <- 0
  for(i in 1:3){
    if(sGuess[i] == sAnswer[i]){
      solids <- solids + 1
    }
  }
  c(blinks,solids)
}

results <- data.frame(blinks = c(),solids = c())
dt1 <- bl1_so1(dt,1,2,3)
for (i in 1:45){
	test <- checkHits(as.vector(dt1[i,]),c(1,2,3))
	print(test)
	results <- bind_rows(results,data.frame(blinks = c(test[1]),solids = c(test[2])))
}

# one blinking
#dt1 <- filter(dt,X1 == 1 | X2 == 2 | X3 == 3)
#dt1 <- filter(dt1,X1 == 4 | X2 == 5 | X3 == 6)
#
##one blink one solid - how does merlin handle 1,1,1 would a guess of 1,2,3 be one blicking, one solid?
#  for 1,2,3 press note: may  be able to remove the correct position number (1 for the first phrase) from these
#
#       because it's not going to count  the correct "1" twice
#
#       a guess of 1,2,3 with one blicking, one solid could be:
#       1,1,1 - no, only one 1 in guess
#       1,1,2
#       1,1,3 - no, three can't be last digit
#       1,2,1 - no, two can't be second digit
#       1,2,2 - no, dido
#       1,2,3 - no, three can't be last digit - would be exact match
#       1,3,1
#       1,3,2 - no, would be two solid
#       1,3,3 - no, three can't be last digit
#       .... all the other digits 4-9
# 
#    //these can be refined
#    (X1 == 1 and X2 == 1 or 3 and X3 == 1 or 2) or
#    (X2 == 2 and X1 == 2 or 3 and X3 == 1 or 2) or 
#    (X3 == 3 and X1 == 2 or 3 and X2 == 1 or 3)
#
#    //
#    (X1 == 1 and X2 == 3 and X3 != 3 ) or
#    (X1 == 1 and X3 == 2 and X2 != 2) or
#    (X2 == 2 and X1 == 2 and X3 != 3 ) or 
#    (X2 == 2 and X3 == 1 and X1 != 1 ) or 
#can remove current position
#op <- c(7,8,9)
#
#dt2 <- filter(dt1,X1 %in% op  | X2 %in% op | X3 %in% op)
#
#
#dt3 <- filter(dt2,X1 == 1 | X2 == 5 | X3 == 7)
#
##no hits
#dt4 <- filter(dt3,X1 != 1 & X2 != 5 & X3 != 8)
#
