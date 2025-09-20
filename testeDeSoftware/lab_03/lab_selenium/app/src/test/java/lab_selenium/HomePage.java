package lab_selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import java.time.Duration;

public class HomePage {
    private WebDriver driver;

    private By homePageTitle = By.tagName("h1");
    private By campoMouraoLink = By.xpath("//a[.//div[contains(text(),'Campo Mourão')]]");

    public HomePage(WebDriver driver) {
        this.driver = driver;
        WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
        wait.until(ExpectedConditions.visibilityOfElementLocated(homePageTitle));
    }

    public String getHomePageTitleText() {
        return driver.findElement(homePageTitle).getText();
    }

    public PortalDoAlunoPage navigateToCampusPage() {
      driver.findElement(campoMouraoLink).click();
      for (String handle : driver.getWindowHandles()) {
          driver.switchTo().window(handle);
      }
      return new PortalDoAlunoPage(driver);
    }
}