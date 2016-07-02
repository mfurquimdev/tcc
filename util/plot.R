library(rgl)

p=c(2,2,2,2,2,2,2,2)
d=c(2,3,4,5,6,7,8,9)
b=c(27,102,361,1251,4296,14746,50746,175230)
s=c(0,0,0,0,0,1,3,19)

p2 = data.frame(p,d,b,s)

p=c(3,3,3,3,3,3)
d=c(2,3,4,5,6,7)
b=c(150,1219,9082,65195,457855,3173596)
s=c(0,1,1,19,653,19929)

p3 = data.frame(p,d,b,s)

p=c(4,4,4)
d=c(2,3,4)
b=c(825,14907,243200)
s=c(0,2,462)

p4 = data.frame(p,d,b,s)

p=c(5,5,5)
d=c(2,3,4)
b=c(4513,178898,6303528)
s=c(0,505,526949)

p5 = data.frame(p,d,b,s)


print (p2)

plot3d(p2$p, p2$d, p2$b, xlab="Peao", ylab="Disco", zlab="Estados", box = FALSE, col = rainbow(8))
lines3d(p2$p, p2$d, p2$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(8))

points3d(p3$p, p3$d, p3$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(6))
lines3d(p3$p, p3$d, p3$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(6))

points3d(p4$p, p4$d, p4$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))
lines3d(p4$p, p4$d, p4$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))

points3d(p5$p, p5$d, p5$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))
lines3d(p5$p, p5$d, p5$b, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))


plot3d(p2$p, p2$d, p2$s, xlab="Peao", ylab="Disco", zlab="Estados", box = FALSE, col = rainbow(8))
lines3d(p2$p, p2$d, p2$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(8))

points3d(p3$p, p3$d, p3$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(6))
lines3d(p3$p, p3$d, p3$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(6))

points3d(p4$p, p4$d, p4$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))
lines3d(p4$p, p4$d, p4$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))

points3d(p5$p, p5$d, p5$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))
lines3d(p5$p, p5$d, p5$s, xlab="Peao", ylab="Disco", zlab="Estados", col = rainbow(4))
