package lab_selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.support.ui.ExpectedConditions;
import java.time.Duration;

public class LoginPage {
    private WebDriver driver;

    // URL da página de login
    private static final String URL = "https://sistemas2.utfpr.edu.br/login";

    // Locators dos elementos da página
    private By usernameField = By.cssSelector("input[formcontrolname='username']");
    private By passwordField = By.cssSelector("input[formcontrolname='password']");
    private By loginButton = By.id("btn-login");
    private By titleDiv = By.id("title");

    public LoginPage(WebDriver driver) {
        this.driver = driver;
    }

    public void navigateTo() {
        driver.get(URL);
    }

    public String getTitle() {
        return driver.findElement(titleDiv).getText();
    }

    public void enterUsername(String username) {
        driver.findElement(usernameField).sendKeys(username);
    }

    public void enterPassword(String password) {
        driver.findElement(passwordField).sendKeys(password);
    }

    public HomePage doLogin(String username, String password) {
        enterUsername(username);
        enterPassword(password);
        
        driver.findElement(loginButton).click();
        WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
        wait.until(ExpectedConditions.not(ExpectedConditions.titleIs(URL)));

        return new HomePage(driver);
    }

}