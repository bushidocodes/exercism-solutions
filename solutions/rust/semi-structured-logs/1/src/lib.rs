/// various log levels
#[derive(Clone, PartialEq, Debug)]
pub enum LogLevel {
    Info,
    Warning,
    Error,
}
/// primary function for emitting logs
pub fn log(level: LogLevel, message: &str) -> String {
    let label = match level {
        LogLevel::Info => "[INFO]",
        LogLevel::Warning => "[WARNING]",
        LogLevel::Error => "[ERROR]",
    };

    let mut res = String::from(label);
    res.push_str(": ");
    res.push_str(message);

    res
}
pub fn info(message: &str) -> String {
    log(LogLevel::Info, message)
}
pub fn warn(message: &str) -> String {
    log(LogLevel::Warning, message)
}
pub fn error(message: &str) -> String {
    log(LogLevel::Error, message)
}
