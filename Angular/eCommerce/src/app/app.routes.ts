import { RouterModule, Routes } from '@angular/router';
import { ItemsListComponent } from './items-list/items-list.component';
//import { ProductDetailComponent } from './product-detail/product-detail.component';
import { RegisterRouteComponent } from "./register/register.component";
import { NotFoundComponent } from './not-found/not-found.component';
import { LoginComponent } from './login/login.component';
import { NgModule } from '@angular/core';

export const routes: Routes = [
  { path: '', component: ItemsListComponent, title: 'Items list' },
 // { path: 'product/:id', component: ProductDetailComponent },
  { path: 'register', component: RegisterRouteComponent, title: 'register page' },
  { path: 'login', component: LoginComponent, title: 'login page' },
  { path: '**', component: NotFoundComponent, title: 'not found page' }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
