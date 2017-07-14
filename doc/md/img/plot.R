#!/usr/bin/Rscript

num_discs <- c()
w1s <- c()
w2s <- c()
ties <- c()
names <- c()
files <- Sys.glob(file.path(".", "*.csv"))
for (f in 1:length(files)) {
	bigpoints <- read.table(sep=",", files[f])
	board = bigpoints[[1]]
	j1 = bigpoints[[2]]
	j2 = bigpoints[[3]]
	states = bigpoints[[4]]
	tempo = bigpoints[[5]]
	w1 <- 0
	w2 <- 0
	tie <- 0
	for (i in 1:length(j1)) {
		if (j1[i] > j2[i]) {
			w1 = w1 + 1
		}
		if (j1[i] < j2[i]) {
			w2 = w2 + 1
		}
		if (j1[i] == j2[i]) {
			tie = tie + 1
		}
	}
	w1s[f] <- (100*w1/length(j1))
	w2s[f] <- (100*w2/length(j1))
	ties[f] <- (100*tie/length(j1))
	names[f] <- paste(substr(files[f],3,3), "C:", substr(files[f],5,5), "D")
	num_discs[f] <- as.numeric(as.character(substr(names[f],3,3)))*as.numeric(as.character(substr(names[f],5,5)))
}

for (rest in length(files)+1:9) {
	w1s[rest] <- NA
	ties[rest] <- NA
	w2s[rest] <- NA
}

library(plot3D)

m <- matrix(w1s, nrow = 3, ncol = 3, byrow = TRUE, dimnames = list(c("C2", "C3", "C4"), c("D2","D3","D4")))
print(m)

hist3D(x=2:4,y=2:4,z=m, border="black", contour=TRUE, theta=-125, phi=45, bty="b2", lighting=TRUE, space=0.2, main="Jogos Reduzidos de Big Points", ylab="Número de Discos", xlab="Número de Cores",zlim=c(0,100),col=rainbow(100, start=0.15, end=1), zlab="% de Vitórias (J1)")


