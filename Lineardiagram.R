# خواندن داده‌ها از فایل خروجی C++
data <- read.table("Large_linear_AVG.txt", header = FALSE)
colnames(data) <- c("n", "steps")

# محاسبه دو برابر لگاریتم در مبنای چهار سوم
log_base <- log(4/3)
data$l1 <- data$n
data$l2 <- 2 * data$n
data$l3 <- 3 * data$n

# رسم نمودار
plot(data$n, data$steps, col="red", pch=20, cex=0.6, xlab="n", ylab="Steps / 2*log4/3(n)")
lines(data$n, data$l1, col="yellow", lwd=1.5)
lines(data$n, data$l2, col="blue", lwd=1.5)
lines(data$n, data$l3, col="green", lwd=1.5)

legend("topright", legend=c("Collatz Steps", "2*log4/3(n)"), col=c("red", "blue"), pch=c(20, NA), lty=c(NA, 1), lwd=c(NA, 1.5))
# ...existing code...

# ذخیره نمودار به عنوان فایل PNG
png("Large_linear_AVG.png", width=1400, height=600)

plot(data$n, data$steps, col="red", pch=20, cex=0.6, xlab="n", ylab="Steps / 2*log4/3(n)")
lines(data$n, data$l1, col="yellow", lwd=1.5)
lines(data$n, data$l2, col="blue", lwd=1.5)
lines(data$n, data$l3, col="green", lwd=1.5)
legend("topright", legend=c("Collatz Steps", "2*log4/3(n)"), col=c("red", "blue"), pch=c(20, NA), lty=c(NA, 1), lwd=c(NA, 1.5))

dev.off()
# ...existing code...