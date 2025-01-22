import { Component } from '@angular/core';
import { RouterLink } from '@angular/router';
import { FormsModule, NgForm } from '@angular/forms';
@Component({
  selector: 'app-login',
  imports: [RouterLink, FormsModule],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent {
  submit(val: NgForm){
    console.log(val);
    
  }
}