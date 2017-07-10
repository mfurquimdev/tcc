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
	time = bigpoints[[5]]
	
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

	w1s[f] <- (w1/length(j1)*100)
	w2s[f] <- (w2/length(j1)*100)
	ties[f] <- (tie/length(j1)*100)

	names[f] <- paste(substr(files[f],3,3), "C:", substr(files[f],5,5), "D")
	
	num_discs[f] <- as.numeric(as.character(substr(names[f],3,3)))*as.numeric(as.character(substr(names[f],5,5)))
#	plot(j1,j2, main = "Main title", sub = "sub title" , ylab = "Y axis", xlab = "X axis")
#	print(paste(files[f], " ", w1, ":", tie, ":", w2, sep=""))
}

print(paste(names, "->", w1s, ":", ties, ":", w2s, sep=""))

png(filename="./ordem_num_cores.png", height=480, width=854, bg="white")
plot_colors <- c("blue","red","forestgreen")
data <- data.frame(w1s,w2s,ties)
plot(data$w1s, type="b", col=plot_colors[1], ylim=c(0,100), axes=FALSE, ann=FALSE)
lines(data$w2s, type="b", col=plot_colors[2], pch=22, lty=8)
lines(data$ties, type="b", col=plot_colors[3], pch=24, lty=4)
axis(1, at=1:length(names), lab=names)
axis(2, las=1, at=c(0,20,40,60,80,100))
box()
title(main="Big Points", col.main="black", font.main=4)
title(xlab= "Tamanho do Jogo")
title(ylab= "% de vitórias")
abline(h=(seq(0,100,20)), col="lightgray", lty="dotted")
legend("topright", c("Jogador 1", "Jogador 2", "Empate"), cex=0.8, col=plot_colors, pch=c(18,22,24), lty=c(1,8,4), lwd=2, bty="n")
dev.off()

tmp <- w1s[3]
w1s[3] <- w1s[4]
w1s[4] <- tmp
tmp <- w1s[7]
w1s[7] <- w1s[6]
w1s[6] <- w1s[5]
w1s[5] <- tmp

tmp <- w2s[3]
w2s[3] <- w2s[4]
w2s[4] <- tmp
tmp <- w2s[7]
w2s[7] <- w2s[6]
w2s[6] <- w2s[5]
w2s[5] <- tmp

tmp <- ties[3]
ties[3] <- ties[4]
ties[4] <- tmp
tmp <- ties[7]
ties[7] <- ties[6]
ties[6] <- ties[5]
ties[5] <- tmp

tmp <- names[3]
names[3] <- names[4]
names[4] <- tmp
tmp <- names[7]
names[7] <- names[6]
names[6] <- names[5]
names[5] <- tmp

print(paste(names, "->", w1s, ":", ties, ":", w2s, sep=""))

png(filename="./ordem_tamanho.png", height=480, width=854, bg="white")
plot_colors <- c("blue","red","forestgreen")
data <- data.frame(w1s,w2s,ties)
plot(data$w1s, type="b", col=plot_colors[1], ylim=c(0,100), axes=FALSE, ann=FALSE)
lines(data$w2s, type="b", col=plot_colors[2], pch=22, lty=5)
lines(data$ties, type="b", col=plot_colors[3], pch=24, lty=4)
axis(1, at=1:length(names), lab=names)
axis(2, las=1, at=c(0,20,40,60,80,100))
box()
title(main="Big Points", col.main="black", font.main=4)
title(xlab= "Tamanho do Jogo")
title(ylab= "% de vitórias")
abline(h=(seq(0,100,20)), col="lightgray", lty="dotted")
legend("topright", c("Jogador 1", "Jogador 2", "Empate"), cex=0.8, col=plot_colors, pch=c(18,22,24), lty=c(1,8,4), lwd=2, bty="n")
dev.off()

tmp <- w1s[2]
w1s[2] <- w1s[3]
w1s[3] <- w1s[5]
w1s[5] <- w1s[6]
w1s[6] <- w1s[4]
w1s[4] <- tmp

tmp <- w2s[2]
w2s[2] <- w2s[3]
w2s[3] <- w2s[5]
w2s[5] <- w2s[6]
w2s[6] <- w2s[4]
w2s[4] <- tmp

tmp <- ties[2]
ties[2] <- ties[3]
ties[3] <- ties[5]
ties[5] <- ties[6]
ties[6] <- ties[4]
ties[4] <- tmp

tmp <- names[2]
names[2] <- names[3]
names[3] <- names[5]
names[5] <- names[6]
names[6] <- names[4]
names[4] <- tmp

print(paste(names, "->", w1s, ":", ties, ":", w2s, sep=""))
png(filename="./ordem_num_discos.png", height=480, width=854, bg="white")
plot_colors <- c("blue","red","forestgreen")
data <- data.frame(w1s,w2s,ties)
plot(data$w1s, type="b", col=plot_colors[1], ylim=c(0,100), axes=FALSE, ann=FALSE)
lines(data$w2s, type="b", col=plot_colors[2], pch=22, lty=5)
lines(data$ties, type="b", col=plot_colors[3], pch=24, lty=4)
axis(1, at=1:length(names), lab=names)
axis(2, las=1, at=c(0,20,40,60,80,100))
box()
title(main="Big Points", col.main="black", font.main=4)
title(xlab= "Tamanho do Jogo")
title(ylab= "% de vitórias")
abline(h=(seq(0,100,20)), col="lightgray", lty="dotted")
legend("topright", c("Jogador 1", "Jogador 2", "Empate"), cex=0.8, col=plot_colors, pch=c(18,22,24), lty=c(1,8,4), lwd=2, bty="n")
dev.off()

