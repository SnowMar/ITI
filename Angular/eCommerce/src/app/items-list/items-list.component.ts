import { Router } from '@angular/router';
import { ProductService } from '../services/product.service';
import { Item } from '../types/item';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-items-list',
  templateUrl: './items-list.component.html',
  styleUrls: ['./items-list.component.css']
})
export class ItemsListComponent implements OnInit {
  products: Item[] = [];
  loading = false;

  constructor(private productService: ProductService, private router: Router) {}

  ngOnInit(): void {
    this.loading = true;
    this.productService.getAllProducts().subscribe({
      next: (products) => {
        this.products = products;
        this.loading = false;
      },
      error: (error) => {
        console.error('Error:', error);
        this.loading = false;
      }
    });
  }

  redirectToProductDetails(productId: number): void {
    this.router.navigate(['/product', productId]);
  }
}