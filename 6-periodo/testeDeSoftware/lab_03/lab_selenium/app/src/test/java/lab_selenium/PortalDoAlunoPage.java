package lab_selenium;

import java.time.Duration;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

public class PortalDoAlunoPage {
  private WebDriver driver;
  
  private By professorsMapLink = By.xpath("//div[@class='card-content'][.//span[text()='Mapa De Professores']]");
  private By enrolledSubjectsLink = By.xpath("//div[@class='card-content'][.//span[text()='Disciplinas Matriculadas']]");
  private By departamentoSelect = By.id("pm_deptoacadnr");
  private By professorSelect = By.id("pm_profmnemcodnr");
  private By pageTitle = By.xpath("//td[text()='Mapa de Professor']");
  private By iFrame = By.id("if_navega");
  private By alunoTd = By.xpath("//td[@class='stdleft' and @colspan='3'][.//strong[text()='Aluno:']]");

  public PortalDoAlunoPage(WebDriver driver) {
    this.driver = driver;
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    wait.until(ExpectedConditions.titleContains("Portal do Aluno"));
  }

  public String getPageTitle() {
    return driver.getTitle();
  }

  public String getSectionTitle() {
    return driver.findElement(pageTitle).getText();
  }

  public void closeModalIfPresent() {
    try {
      WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
      By closeModalButton = By.xpath("//div[@id='myModal']//span[@class='close']");
      wait.until(ExpectedConditions.visibilityOfElementLocated(closeModalButton));
      driver.findElement(closeModalButton).click();
      wait.until(ExpectedConditions.invisibilityOfElementLocated(closeModalButton));
    } catch (Exception e) {
      // Se o modal não estiver presente, não faz nada
    }
  }

  public void clickProfessorsMap() {
    closeModalIfPresent();
    driver.findElement(professorsMapLink).click();
    
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    wait.until(ExpectedConditions.frameToBeAvailableAndSwitchToIt(iFrame));

    wait.until(ExpectedConditions.visibilityOfElementLocated(departamentoSelect));
  }

  public void selectDepartment(String departmentValue, String departmentName) { 
    By option = By.xpath("//select[@id='pm_deptoacadnr']/option[@value='" + departmentValue + "']");
    driver.findElement(departamentoSelect).click();
    driver.findElement(option).click();
    
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    wait.until(ExpectedConditions.textToBePresentInElementLocated(departamentoSelect, departmentName));
  }

  public void selectProfessor(String professorValue, String professorName) {
    By professorOption = By.xpath("//select[@id='pm_profmnemcodnr']/option[@value='" + professorValue + "']");
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(20));

    wait.until(driver -> driver.findElements(By.xpath("//select[@id='pm_profmnemcodnr']/option")).size() > 1);

    wait.until(ExpectedConditions.elementToBeClickable(professorSelect));

    wait.until(ExpectedConditions.presenceOfElementLocated(professorOption));
    wait.until(ExpectedConditions.visibilityOfElementLocated(professorOption));

    // Seleciona o professor
    driver.findElement(professorSelect).click();
    driver.findElement(professorOption).click();

    // Confirma que o professor foi selecionado
    wait.until(ExpectedConditions.textToBePresentInElementLocated(professorSelect, professorName));
  }

  public void clickSearchButton() {
    By searchButton = By.id("bt_pesquisar");
    driver.findElement(searchButton).click();
    
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    By resultsTable = By.className("horarios");
    wait.until(ExpectedConditions.visibilityOfElementLocated(resultsTable));
  }

  public String waitForMapaDeAulasEPermanencias() {
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    By mapaDeAulas = By.xpath("//strong[contains(text(),'Mapa de Aulas e Permanências')]");
    return wait.until(driver -> driver.findElement(mapaDeAulas).getText());
  }

  public void clickEnrolledSubjects() {
    closeModalIfPresent();
    driver.findElement(enrolledSubjectsLink).click();

    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    wait.until(ExpectedConditions.frameToBeAvailableAndSwitchToIt(iFrame));

    wait.until(ExpectedConditions.visibilityOfElementLocated(alunoTd));
  }

  public void waitForEnrolledSubjectsTable() {
    WebDriverWait wait = new WebDriverWait(driver, Duration.ofSeconds(10));
    By enrolledTable = By.xpath("//table[@class='tbl']//th[text()='Campus']");
    wait.until(ExpectedConditions.visibilityOfElementLocated(enrolledTable));
  }
}
