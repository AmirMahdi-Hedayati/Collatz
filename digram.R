# خواندن داده‌ها از فایل خروجی C++
data <- read.table("collatz_output.txt", header = FALSE)
colnames(data) <- c("n", "steps")

# محاسبه دو برابر لگاریتم در مبنای چهار سوم
log_base <- log(4/3)
data$log_approx1 <- log(data$n) / log_base
data$log_approx2 <- 2 * log(data$n) / log_base
data$log_approx3 <- 3 * log(data$n) / log_base

# رسم نمودار
plot(data$n, data$steps, col="red", pch=20, cex=0.6, xlab="n", ylab="Steps / 2*log4/3(n)")
lines(data$n, data$log_approx1, col="yellow", lwd=1.5)
lines(data$n, data$log_approx2, col="blue", lwd=1.5)
lines(data$n, data$log_approx3, col="green", lwd=1.5)

legend("topright", legend=c("Collatz Steps", "2*log4/3(n)"), col=c("red", "blue"), pch=c(20, NA), lty=c(NA, 1), lwd=c(NA, 1.5))
# ...existing code...

# ذخیره نمودار به عنوان فایل PNG
png("collatz2_diagram.png", width=1400, height=600)

plot(data$n, data$steps, col="red", pch=20, cex=0.6, xlab="n", ylab="Steps / 2*log4/3(n)")
lines(data$n, data$log_approx1, col="yellow", lwd=1.5)
lines(data$n, data$log_approx2, col="blue", lwd=1.5)
lines(data$n, data$log_approx3, col="green", lwd=1.5)
legend("topright", legend=c("Collatz Steps", "2*log4/3(n)"), col=c("red", "blue"), pch=c(20, NA), lty=c(NA, 1), lwd=c(NA, 1.5))

dev.off()
# ...existing code...